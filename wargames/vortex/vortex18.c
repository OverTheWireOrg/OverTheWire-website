/*
 * vortex18 challenge
 * 
 * written by Tim Newsham
 * contributions by Joshua J. Drake
 */


#include <stdio.h>

#define RANDLEN 16
#define BUFLEN 20

#define TERMINATE1 'n'
#define TERMINATE2 's'
#define TERMINATE3 '$'
#define TERMINATE4 'S'

void
seedrand(char *seed)
{
    char buf[RANDLEN];
    int fd, i;

    /* read in a seed */
    fd = open("/dev/urandom", 0);
    if(fd == -1) 
        exit(1);
    if(read(fd, buf, sizeof buf) != sizeof buf)
        exit(2);
    close(fd);

    /* make sure it doesnt use the terminator */
    for(i = 0; i < RANDLEN - 1; i++) {
        if(buf[i] == TERMINATE1 
           || buf[i] == TERMINATE2 
           || buf[i] == TERMINATE3
           || buf[i] == TERMINATE4
           || buf[i] == '\0')
            buf[i] = ' ';
    }
    buf[i] = 0;

    /* return it */
    strcpy(seed, buf);
}

int
guess(char *seed)
{
    char buf[BUFLEN];
    int i;

    for(i = 0; i < BUFLEN - 1; i++) {
        if(read(0, buf + i, 1) != 1)
            exit(1);
        if(buf[i] == TERMINATE1 
           || buf[i] == TERMINATE2
           || buf[i] == TERMINATE3
           || buf[i] == TERMINATE4)
            break;
    }
    buf[i] = 0;
    
    if(strcmp(buf, seed) == 0)
        return 1;
    printf(buf);
    printf("\n");
    fflush(stdout);
    return 0;
}

int
main(int argc, char **argv)
{
    char seed[RANDLEN];
    int i;

    seedrand(seed);
    for(i = 0; i < 10; i++) {
        if(guess(seed)) {
            i = geteuid();
            setresuid(i, i, i);
            write(1, "YAY!\n", 5);
            execlp("/bin/sh", "sh", 0);
            exit(0);
        }
    }

    printf("sorry.\n");
    return 0;
}
