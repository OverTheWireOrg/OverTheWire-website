#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <wait.h>


#include "server.h"
#include "sem.h"

#define PATH "/path"
#define SHM_SIZE 4096
#define SHM_KEY 0xbadc0ded
#define AUTH_PORT 24012
#define BUFSIZE 512

int new_connection(unsigned int addr, int pass, struct sharea* auth_array);
int daemonize();

int main(int argc, char **argv)
{
        if(argc > 1) {
                if((argv[1][0] == 'D')) {
                        if((daemonize()) == -1)
                                exit(EXIT_FAILURE);
                }
        }
        
        int                     fd, sockfd, connfd;
        unsigned int            sin_size;
        struct sockaddr_in      my_addr, remote_addr;
        struct sigaction        reap_zombies;

        key_t           key = SHM_KEY;
        int             shmid;
        struct sharea   *auth_array;

        char            sendbuf[BUFSIZE], recvbuf[BUFSIZE], super_pass[BUFSIZE];        

        fd = open(PATH, O_RDONLY);
        if(fd < 0) {
                perror("open");
                exit(EXIT_FAILURE);
        }

        if((read(fd, super_pass, BUFSIZE)) < 0) {
                perror("pass");
                exit(EXIT_FAILURE);
        }
        close(fd);

        /*Set up the shared memory authorization array */

        if((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
                perror("Shared");
                exit(1);
        }
        
        if((auth_array = shmat(shmid, NULL, 0)) == (void *)-1) {
                perror("Share attach");
                exit(1);
        }

        memset(auth_array, 0, sizeof(*auth_array));
        
        memset(&reap_zombies, 0, sizeof(reap_zombies));
        reap_zombies.sa_flags = SA_NOCLDWAIT;

        if((sigaction(SIGCHLD, &reap_zombies, 0)) == -1) {
                perror("Sighandler");
                exit(1);
        }
        
        /* Lets set up the listening socket */

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

                pid_t   pid;
                
                sin_size = sizeof(struct sockaddr_in);
                if((connfd = accept(sockfd, (struct sockaddr*)&remote_addr, &sin_size)) == -1) {
                        perror("Accept");
                        exit(1);
                }
                
                pid = fork();
                if(pid < 0) {
                        perror("fork");
                        exit(EXIT_FAILURE);
                }
                if(pid > 0) {
                        close(connfd);
                        continue;
                }               
                
                strcpy(sendbuf, "Authd login - Send Pass");
                send(connfd, sendbuf, strlen(sendbuf), 0);
                recv(connfd, recvbuf, BUFSIZE - 1, 0);
                recvbuf[BUFSIZE - 1] = '\0';
                
                if(!new_connection(remote_addr.sin_addr.s_addr, strcmp(recvbuf, super_pass), auth_array)) {
                        strcpy(sendbuf, "Failed - try again later");
                        send(connfd, sendbuf, strlen(sendbuf), 0);
                }
                close(connfd);
                exit(EXIT_SUCCESS);
        }
}

int new_connection(unsigned int addr, int super, struct sharea *auth_array)
{
        int i, found = 0;

        /* Insert new entry with correct perms */
        
        down(&auth_array->sem);
        for(i = 0; i < 32; i++) {
                if(auth_array->list[i].token == 0) {
                        found++;
                        auth_array->list[i].token = addr;
                        auth_array->list[i].timestamp = time(NULL);
                        if(super)
                                auth_array->list[i].perms = 1;  /* 1 = ordinary user */
                        break;
                }
                                                
        }
        up(&auth_array->sem);

        /* Expire old connections */
        down(&auth_array->sem);
        for(i = 0; i < 32; i++) {
                if((auth_array->list[i].timestamp + 300) < time(NULL)) 
                        memset(&auth_array->list[i], 0, sizeof(struct auth));
        }
        up(&auth_array->sem);
        
        return found;
}
