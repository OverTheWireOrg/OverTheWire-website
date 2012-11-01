#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <pwd.h>

void wipearray(char **array)
{
    /*
     * This should be pretty trivial without relying on stack
     * values :)
     */

    while(*array) {
        memset(*array, 0, strlen(*array));
        array++;
    }
}

void wipeenv(char **argv, char **envp)
{
    wipearray(argv);
    wipearray(envp);
}

char* do_finger()
{
    char buf[80], *p;
    gets(buf);
    p = buf;
    while(*p) {
        *p = toupper(*p);
        p++;
    }

    return strdup(p);
}

int main(int argc, char **argv, char **envp)
{
    /*
     * This idea is taken from a question in #social one day about
     * what to do if a process is being traced and you can't execve()
     */

    if(ptrace(PTRACE_TRACEME) == -1) {
        printf("request for tracing failed\n");
        exit(EXIT_FAILURE);
    }

    wipeenv(argv, envp);

    do_finger();
}
