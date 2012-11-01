#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {
        char *p;
        char *q;
        char *r;
        char *s;
        if (argc < 3)
        {
                exit(0);
        }
        p = (char *) malloc(0x800);
        q = (char *) malloc(0x10);
        r = (char *) malloc(0x800);
        strcpy(r , argv[1]);
        s = (char *) malloc(0x10);
        strncpy(s , argv[2], 0xf);
        exit(0);
}
