/*
 *      multivitamin.c 2006 by aton@packetdropped.org
 *
 *      rules: no patching.
 *      compile: gcc multivitamin.c -o multivitamin -lgmp
 *
 *      -> multiplication is simple, and so is division...?
 */


#define _GNU_SOURCE
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <gmp.h>

#define ADDVALUE 27137

int main(int argc, char *argv[])
{
        mpz_t longjohn, mul, cmpval;
        char userstr[512+1];
        int n=0;

        mpz_init(longjohn);
        mpz_set_ui(longjohn, 1);
        mpz_init(mul);
        mpz_init(cmpval);
        mpz_set_str(cmpval, "insert-here-the-password-hash-from-your-home-directory-on-semtex-7", 10);

        if (argc<2)
        {
                printf("%s <string>\n", argv[0]);
                return -1;
        }

        strncpy(userstr, argv[1], 512);

        for (n=0;n<strlen(userstr);n++)
        {
                mpz_set_ui(mul, (unsigned long)(userstr[n]+ADDVALUE));
                mpz_mul(longjohn, longjohn, mul);
        }

        if (!(n=mpz_cmp(longjohn, cmpval)))
        {
                setresuid(geteuid(), geteuid(), geteuid());
                execlp("/bin/bash", "bash", NULL);
        }
        else
                printf("err... booom!\n");

        return 0;
}
