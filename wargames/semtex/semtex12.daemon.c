#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#define _GNU_SOURCE
#include <unistd.h>


#define TARGET_UID 1998

int daemonize()
{
        int ret = -1;

        if((daemon(0, 0)) == -1)
                return ret;

        if((setresgid(TARGET_UID, TARGET_UID, TARGET_UID)) == -1)
                return ret;
        if((setresuid(TARGET_UID, TARGET_UID, TARGET_UID)) == -1)
                return ret;

        ret = 0;

        return ret;
        
}
