/*
Written by conscon


Hint: Analyze random_r.c from GLIBC Source
*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>

void alrm(int signo)
{
        printf("Operation timed out\n");
        exit(EXIT_SUCCESS);
}
int main()
{
        int fd, i, j,word;
        int seed,guess;
        unsigned int rr[31];

        fd = open("/dev/urandom", O_RDONLY);
        if(fd < 0) {
                perror("/dev/urandom");
                exit(EXIT_FAILURE);
        }
        alarm(60);
        signal(SIGALRM, alrm);

        for(j=0;j<20;j++)
        {

                if(read(fd, &seed, sizeof(unsigned int)) != sizeof(unsigned int)) {
                        perror("read /dev/urandom");
                        exit(EXIT_FAILURE);
                }

                srand(seed);

                for(i = 0; i < 29; i++) {
                        printf(" %d",rand());
                        if((i%5)==4)printf("\n");
                }
                printf("\n");
                fflush(stdout);
                scanf("%d",&guess);
                if(guess!=seed) exit(EXIT_FAILURE);
        }

        setresgid(getegid(), getegid(), getegid());
        setresuid(geteuid(),geteuid(), geteuid());
        execlp("/bin/sh", "sh", NULL);

        return 0;
}
