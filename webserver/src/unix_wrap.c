//
// Created by Jesse on 2018/10/2.
//

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <signal.h>
#include <sys/resource.h>


#include "unix_wrap.h"

pid_t Fork()
{
    pid_t pid;

    if((pid=fork()) < 0){
        fprintf(stderr, "%s: %s\n", "fork error:", strerror(errno));
        exit(0);
    }

    return pid;
}

int Open(const char *pathname, int flags, mode_t mode)
{
    int n;

    if ((n=open(pathname, flags, mode)) < 0) {
        fprintf(stderr, "%s: %s\n", "open error:", strerror(errno));
        exit(1);
    }

    return n;
}

FILE * Fopen(const char * path, const char * mode)
{
    FILE * fd;


    if ((fd = fopen(path, mode)) == NULL)
    {
        fprintf(stderr, "%s: %s\n", "fopen error:", strerror(errno));
        exit(1);
    }

    return fd;
}


void init_daemon(const char *cmd)
{
    int                 i, fd0, fd1, fd2;
    pid_t               pid;
    struct rlimit       rl;
    struct sigaction    sa;
    /*
     *      * Clear file creation mask.
     *           */
    umask(0);

    /*
     *      * Get maximum number of file descriptors.
     *           */
    if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
        perror(cmd);
        exit(1);
    }

    /*
     *      * Become a session leader to lose controlling TTY.
     *           */
    pid = Fork();
    if (pid != 0) /* parent */
        exit(0);
    setsid();

    /*
     *      * Ensure future opens won't allocate controlling TTYs.
     *           */
    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGHUP, &sa, NULL) < 0) {
        perror("Can't ignore SIGHUP");
        exit(1);
    }
    pid = Fork();
    if (pid != 0) /* parent */
        exit(0);

    pid_t daemon_pid = getpid();
    printf("Daemon pid: %d\n", daemon_pid);

    /*
     *      * Close all open file descriptors.
     *           */
    if (rl.rlim_max == RLIM_INFINITY)
        rl.rlim_max = 1024;
    for (i = 0; i < rl.rlim_max; i++)
        close(i);

    /*
     *      * Attach file descriptors 0, 1, and 2 to /dev/null.
     *           */
    fd0 = open("/dev/null", O_RDWR);
    fd1 = dup(0);
    fd2 = dup(0);

    signal(SIGCHLD, SIG_IGN);

}




