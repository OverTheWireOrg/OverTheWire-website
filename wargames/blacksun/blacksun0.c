#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <fcntl.h>

void query(char *username);


int main()
{
	int y0;	 // special marker, you can use this for when you're doing exploition analysis to find where main is on the stack etc.
	int cont;
	char username[256];
	char blah[20];
	
	//setvbuf(stdin, NULL, _IONBF, 0);
	//setvbuf(stdout, NULL, _IONBF, 0);

#ifdef DEBUG
	y0 = open("/proc/self/maps", O_RDONLY);

	while((cont = read(y0, username, sizeof(username))) > 0) {
		write(1, username, cont);
	}
	close(y0);
#endif
	
	printf("--> Blacksun level 0\r\n");
	printf("by Andrew Griffiths (andrewg@felinemenace.org)\r\n");
	printf("/-------------------------------------------------\\ \r\n");
	printf("|Use netcat as opposed to telnet -- telnet sends  |\r\n");
	printf("|certain control charachers and will fuck up your |\r\n");
	printf("|connection. This won't be a problem if you're    |\r\n"); 
	printf("|coding the program to connect.                   |\r\n");
	printf("\\-------------------------------------------------/\r\n\r\n");

	memset(username, 0, sizeof(username));
	cont = 1;

	while(cont) {
		printf("Enter request number: ");
		fflush(stdout);
		fgets(blah, sizeof(blah)-1, stdin);
		y0 = atoi(blah);
		
#ifdef DEBUG
		printf("blah: %p\n", blah);
		printf("username: %p\n", username);
		printf("y0: %p\n", &y0);
#endif
		
		cont = (y0 != 0);
		
		printf("Enter the username you'd like to query: ");
		fflush(stdout);
		gets(username);

		username[strlen(username)] = 0;
		
		
		query(username);

	}
	
	return 0;
}


void query(char *username)
{
	struct passwd *pw;
	char response[4096];
	
	pw = getpwnam(username);

	if(pw) {
		sprintf(response, "Username: %s, uid: %d, gid: %d, gecos: %s, dir: %s, shell: %s\n\n", pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_gecos, pw->pw_dir, pw->pw_shell); 
	} else {
		sprintf(response, "%s does not exist on this system, according to getpwnam().\n\n", username);
	}

#ifdef DEBUG
	printf("response: %p\n", response);
#endif
	
	printf(response);
}

