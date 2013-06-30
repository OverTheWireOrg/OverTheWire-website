/*
 * 0xbadc0ded.org Challenge #02 (2003-07-08)
 *
 * Joel Eriksson <je@0xbadc0ded.org>
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

unsigned long val = 31337;
unsigned long *lp = &val;

int main(int argc, char **argv)
{
        unsigned long **lpp = &lp, *tmp;
        char buf[128];

        if (argc != 2)
                exit(1);

        strcpy(buf, argv[1]);

        if (((unsigned long) lpp & 0xffff0000) != 0x08040000)
                exit(2);

        tmp = *lpp;
        **lpp = (unsigned long) &buf;
        // *lpp = tmp; // Fix suggested by Michael Weissbacher @mweissbacher 2013-06-30

        exit(0);
}

