#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
pid_t pid;

    if (argc < 2)
    {
        printf("\n nincs kinek terminálódni.\n");
        exit(1);
    }

    pid = atoi(argv[1]);
    kill(pid, SIGALRM);
    exit(0);

}
