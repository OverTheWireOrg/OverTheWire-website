/*
 * Level 0 for drifter - Jan 16th, 2008
 *
 * This is an extremely simple / stupid remote procedure call implementation
 * that allows system calls and parameters to be supplied directly, and 
 * return codes written to the caller. 
 *
 * For security reasons, it is chrooted and drops privileges, and in addition,
 * the connection is encrypted. (The previous sentence is a joke..)
 *
 * In the chroot directory, there is a file called 'instructions', open that, 
 * read the contents, and you'll know what to do next.
 *
 * In order to make things easier for yourself, there is plenty of tools 
 * out there already - I suggest that you read up and learn about them.
 *
 * - a scripting language (I humbly suggest Python, but whatever you're most
 *   comfortable with)
 * - http://oss.coresecurity.com/projects/inlineegg.html
 * - mosdef - http://www.immunitysec.com/resources-freesoftware.shtml
 * - http://archives.neohapsis.com/archives/vuln-dev/2003-q4/0006.html
 * - metasploit.com
 * - Plenty of other things :)
 *
 * To compile this code, gcc level0.c rc4.c -o /drifter/level0
 */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <string.h>
#include <sys/syscall.h>
#include <signal.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#include "rc4.h"


void dropprivs()
{
	int groups[1];

	#ifndef LEVELUID
	#error LEVELUID is not defined
	#endif
	
	#define LEVEL0 LEVELUID
	groups[0] = LEVEL0;
	if(setgroups(1, groups) != 0) exit(15);
	if(setresgid(LEVEL0, LEVEL0, LEVEL0) != 0) exit(4);
	if(setresuid(LEVEL0, LEVEL0, LEVEL0) != 0) exit(5);
	#undef LEVEL0
}

void setup_stuff()
{
	/* Become a daemon, and drop privileges, chroot off, etc. */

	signal(SIGCHLD, SIG_IGN); // ignore children.. seems to work :p

	//if(daemon(0, 0) != 0) exit(1);

	if(chroot("/home/drifter0/chroot") != 0) exit(2);
	if(chdir("/") != 0) exit(3);
	dropprivs();
}

int create_socket()
{
	/* Create / bind / listen on socket */

	int ret;
	struct sockaddr_in sin;

	ret = socket(AF_INET, SOCK_STREAM, 0);
	if(ret == -1) exit(6);

	memset(&sin, 0, sizeof(struct sockaddr_in));
	sin.sin_family = AF_INET,
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_port = htons(1111);

	if(bind(ret, (void *)&sin, sizeof(struct sockaddr_in)) == -1) exit(7);

	if(listen(ret, 5) == -1) exit(8);

	return ret;

}

void handle_client(int skt, struct sockaddr_in *sin)
{
	// Handle the client connection, and perform the requested operations.
	
	rc4_key key_in, key_out;
	unsigned char keymat[6];
	unsigned int args[9];
	int i, ret;

	//dropprivs();

	memcpy(keymat, &(sin->sin_addr.s_addr), 4);
	memcpy(keymat+4, &(sin->sin_port), 2);

	prepare_key(keymat, 6, &key_in);
	prepare_key(keymat, 6, &key_out);

	for(i=0;i<42;i++) {
		// cycle through first 256 bytes
		rc4(keymat, 6, &key_in);
		rc4(keymat, 6, &key_out);
	}

	while(1) {
		alarm(60);
		sleep(1);

		if(read(skt, &args, sizeof(args)) != sizeof(args)) exit(EXIT_SUCCESS);

		rc4(&args, sizeof(args), &key_in);
		
		ret = syscall(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8]);

		rc4(&ret, sizeof(int), &key_out);

		if(write(skt, &ret, sizeof(ret)) != sizeof(ret)) exit(EXIT_SUCCESS);

	}

}

void mainloop()
{
	int skt;
	int cli;
	int so;
	int ret;

	struct sockaddr_in sin;

	skt = create_socket();

	while(1) {
		so = sizeof(struct sockaddr_in);
		cli = accept(skt, (void *)&sin, &so);
		if(cli == -1) exit(9);

		ret = fork();
		if(ret == -1) exit(10);
		
		// parent
		
		if(ret) {
			close(cli);
			continue;
		}

		// child
		close(skt);
		handle_client(cli, &sin);
		exit(EXIT_SUCCESS);
	}
}

int main(int argc, char **argv)
{
	setup_stuff();

	mainloop();	
}
