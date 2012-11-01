#include <unistd.h>


/* Get the semaphore and busy wait if held already */

void down(int *sem)
{
retry:
        while(*sem)
                sleep(5);
        (*sem)++;
        if(*sem > 1) {
                (*sem)--;
                goto retry;
        }
        return;
}

/* Try and get the semaphore, but return 0 if held */

int try_down(int *sem)
{
        if(*sem)
                return 0;
        (*sem)++;
        if(*sem > 1) {
                (*sem)--;
                return 0;
        }
        return *sem;
}

/* Release the semaphore */

void up(int *sem)
{
        *sem = 0;
}
