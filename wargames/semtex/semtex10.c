#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>


#define LISTENPORT 24019
#define REALPWD "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
#define OLDPWD "XXXXXXXXXXXXXXXX"
#define DROPUID 1998
#define DROPGID 1998

struct query
{
        unsigned char oldpass[20+1];
        unsigned char pass[100+1];
        unsigned int len;
} qry;

struct response
{
        unsigned int result;
        unsigned char pass[100+1];
} rsp;

int main(int argc, char *argv[])
{
        int listenfd, connfd;
        struct sockaddr_in localaddr;
        struct sockaddr_in remoteaddr;
        int sin_size;
        int port=LISTENPORT;

        setresgid(DROPGID, DROPGID, DROPGID);
        setresuid(DROPUID, DROPUID, DROPUID);
        signal(SIGPIPE, SIG_IGN);
        daemon(0,0);

        if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        {
                perror("socket");
                exit(EXIT_FAILURE);
        }

        localaddr.sin_family = AF_INET;
        localaddr.sin_port = htons(port);
        localaddr.sin_addr.s_addr = INADDR_ANY;
        bzero(&(localaddr.sin_zero), 8);

        if (bind(listenfd, (struct sockaddr *)&localaddr, sizeof(struct sockaddr)) == -1)
        {
                perror("bind");
                exit(EXIT_FAILURE);
        }

        if (listen(listenfd, 20) == -1)
        {
                perror("listen");
                exit(EXIT_FAILURE);
        }

        for (;;)
        {
                sin_size = sizeof(struct sockaddr_in);
                if ((connfd = accept(listenfd, (struct sockaddr *)&remoteaddr, &sin_size)) == -1)
                {
                        perror("accept");
                        continue;
                }

//              printf("connection from %s\n",  inet_ntoa(remoteaddr.sin_addr));

                if (!fork()) //child
                {
                        close(listenfd);

                        for (;;)
                        {
                                memset(&qry, 0, sizeof(struct query));
                                memset(&rsp, 0, sizeof(struct response));

                                if (recv(connfd, &qry, sizeof(struct query), 0)!=sizeof(struct query))
                                {
                                        perror("recv");
                                        close(connfd);
                                        exit(EXIT_FAILURE);
                                }

                                if (strncmp(qry.oldpass, OLDPWD, strlen(OLDPWD)))
                                {
                                        close(connfd);
                                        exit(EXIT_FAILURE);
                                }

                                // validate
                                if (!strncmp(qry.pass, REALPWD, qry.len))
                                        rsp.result=1;

                                if (rsp.result && (qry.len==strlen(REALPWD)))
                                        strcpy(rsp.pass, REALPWD);

//                              printf("-> result=%s\n", rsp.result?"CORRECT":"WRONG");
                                if (send(connfd, &rsp, sizeof(struct response), 0)!=sizeof(struct response))
                                {
                                        perror("send");
                                        close(connfd);
                                        exit(EXIT_FAILURE);
                                }
                        }
                }

                while(waitpid(-1,NULL,WNOHANG) > 0);

                close(connfd);
        }

}
