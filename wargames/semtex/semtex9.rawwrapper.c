#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/ip_icmp.h>
#include <string.h>


#define DROPUID 1009
#define DROPGID 1009

// rawwrapper, aton 2004

int main(int argc, char *argv[])
{
        int rfd;
        char *argv0, *argv1;

        if (argc<2)
        {
                printf("usage: rawwrapper <program>\n");
                printf("argv[1] will be the raw socket\n");
                exit(EXIT_FAILURE);
        }

        //open raw socket
        if ((rfd = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP))<0)
        {
                perror("socket");
                return EXIT_FAILURE;
        }

        //drop priviledges
        setresgid(DROPGID, DROPGID, DROPGID);
        setresuid(DROPUID, DROPUID, DROPUID);

        argv0=malloc(strlen(argv[0])+1);
        strcpy(argv0, argv[0]);
        argv1=malloc(strlen(argv[1])+1);
        strcpy(argv1, argv[1]);

        // fill in new argv
        argv[0]=argv1;
        sprintf(argv[1], "%d", rfd);

        //execute the client program
        execve(argv[0], argv, NULL);
        return EXIT_SUCCESS;
}
