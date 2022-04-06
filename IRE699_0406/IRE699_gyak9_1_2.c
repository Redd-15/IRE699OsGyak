#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void kezelo(int i)
{
    printf("Signal kezelese: %d\n", i);
    exit(0);
    return;
}

int main(void)
{
    printf("PID = %d\n", getpid());
    printf("Signal kezelo atvetele: %d\n", signal(SIGALRM, &kezelo));
    while(1)
    {
    printf("lepes\n");
    pause();
    }


}
