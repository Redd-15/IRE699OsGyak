#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void do_nothing(){ ;}
void handleSignals(int sig);

int data = 0;

int main(int argc, char **argv)
{
    signal(SIGUSR1, handleSignals);
    signal(SIGUSR2, handleSignals);
    unsigned sec=1;

    printf("PID = %d\n", getpid());

    while (1) {
        alarm(sec);
        signal(SIGALRM, do_nothing);

        pause();
    }

    return 0;
}


void handleSignals(int sig) {
    if (sig == SIGUSR1) {
        data++;
        printf("SIGUSR1 lett megadva, az értékhez hozzáadtunk egyet, a jelenlegi érték: %d\n", data);
    }

    else if (sig == SIGUSR2) {
        printf("SIGUSR2 lett megadva, a végleges érték: %d\n", data);
        printf("Kilépés!\n\n");
        exit(0);

    }
}
