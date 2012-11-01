#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>


#include "server.h"
#include "sem.h"

#define PATH "/path"
#define SHM_SIZE 4096
#define SHM_KEY 0xbadc0ded
#define AUTH_PORT 24013
#define BUFSIZE 512

int daemonize();

void list_dir(int fd)
{
        DIR             *dirp;
        struct dirent   *dp;
                
        if((dirp = opendir(PATH)) == NULL)
                        return;
        while((dp = readdir(dirp)) != NULL) {
                send(fd, dp->d_name, strlen(dp->d_name), 0);
        }
        return;
}

void filedump(const char *name, int fd)
{
        FILE            *filp;
        char            buf[2048];
        int             ret;
        
        chdir(PATH);
        if((filp = fopen(name, "rb")) == NULL) {
                strcpy(buf, "File not found.");
                send(fd, buf, strlen(buf), 0);
                return;
        }
        do {
                ret = fread(buf, 1, 2048, filp);
                if(ret > 0)
                        send(fd, buf, ret, 0);
                        send(fd, "\n", 1, 0);
        } while(ret >= 2048);
}

int main(int argc, char **argv)
{

        if(argc > 1) {
                if(argv[1][0] == 'D') {
                        if(daemonize())
                                exit(EXIT_SUCCESS);
                }
        }
        
        int                     sockfd, connfd;
        unsigned int            sin_size;
        struct sockaddr_in      my_addr, remote_addr;

        key_t           key = SHM_KEY;
        int             shmid;
        struct sharea   *auth_array;
        struct sigaction        reap_zombies;
        
        char            sendbuf[BUFSIZE], recvbuf[BUFSIZE], filename[BUFSIZE];

        /*Set up the shared memory authorization array */

        if((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
                perror("Shared");
                exit(1);
        }

        if((auth_array = shmat(shmid, NULL, 0)) == (void *)-1) {
                perror("Share attach");
                exit(1);
        }

        /* Lets set up the listening socket */

        memset(&reap_zombies, 0, sizeof(reap_zombies));
        reap_zombies.sa_flags = SA_NOCLDWAIT;

        if((sigaction(SIGCHLD, &reap_zombies, 0)) == -1) {
                perror("Sighandler");
                exit(1);
        }

        if((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
                perror("Socket");
                exit(1);
        }
        my_addr.sin_family = AF_INET;
        my_addr.sin_port = htons(AUTH_PORT);
        my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        memset(&(my_addr.sin_zero), '\0', 8);

        if((bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr))) == -1) {
                perror("Bind");
                exit(1);
        }

        listen(sockfd, 5);      /* Error checks... nah! */
        
        while(1) {

                int i, len, pid, found = 0;

                sin_size = sizeof(struct sockaddr_in);
                if((connfd = accept(sockfd, (struct sockaddr*)&remote_addr, &sin_size)) == -1) {
                        perror("Accept");
                        exit(1);
                }
                
                if((pid = fork()) < 0) {
                        perror("fork");
                        exit(EXIT_FAILURE);
                }
                if(pid) {
                        close(connfd);
                        continue;
                }
                
                strcpy(sendbuf, "File Transfer: Enter 'l' for list or type a filename:");
                send(connfd, sendbuf, strlen(sendbuf), 0);
                len = recv(connfd, recvbuf, BUFSIZE - 1, 0);
                
                if(len <= 0)
                        break;
                
                strncpy(filename, recvbuf, len < BUFSIZE ? len : BUFSIZE);
                filename[BUFSIZE - 1] = '\0';

                down(&auth_array->sem); /* Take semaphore for reading auth list */
                for(i = 0; i < 32; i++) {
                        if(auth_array->list[i].token == remote_addr.sin_addr.s_addr) {
                                found++;
                                break;
                        }
                }
                up(&auth_array->sem); /* Release semaphore to wait on user replies next... avoid deadlock */

                if(!found) {
                        strcpy(sendbuf, "Not recognized, use authd first.");
                        send(connfd, sendbuf, strlen(sendbuf), 0);
                        close(connfd);
                        continue;
                }
                
                if(filename[0] == 'l') {
                        list_dir(connfd);
                }
                else {
                        strcpy(sendbuf, "Display file? (y/n)");
                        /*check perm and display file*/
                        
                        send(connfd, sendbuf, strlen(sendbuf), 0);
                        recv(connfd, recvbuf, BUFSIZE - 1, 0);
                        recvbuf[BUFSIZE - 1] = '\0';
                        
                        if(recvbuf[0] == 'y') {
                                down(&auth_array->sem);
                                if(auth_array->list[i].perms == 0) {/* 0 is superuser, 1 is user */
                                        filedump(filename, connfd);
                                }
                                else {
                                        strcpy(sendbuf, "Not Authorized");
                                        send(connfd, sendbuf, strlen(sendbuf), 0);
                                }
                                up(&auth_array->sem);
                        }

                }
                close(connfd);
                exit(EXIT_SUCCESS);
        }
        return 0;
}
