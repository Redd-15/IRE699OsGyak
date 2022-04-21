#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>


int main(void)
{
    pid_t pid;
    int pidint = 0, cmdint;
    printf("Adja meg a másik process PID-jét!\n PID: ");
    scanf("%d", &pidint);
    pid = (pid_t)pidint;


    while(1)
    {
    printf("Milyen signalt ohajt küldeni? USR1, vagy USR2? (válaszlehetőségek: '1'/'2', más esetben a program kilép): ");
    scanf("%d", &cmdint);
    printf("\n");

    if (cmdint == 1){

    int ret;
    ret = kill(pid,SIGUSR1);
    printf("ret : %d",ret);

    printf("USR1 signal kiküldve a (PID: %d) processnek!\n",pidint);
    }
    else if (cmdint == 2){

    int ret;
    ret = kill(pid,SIGUSR2);
    printf("ret : %d",ret);

    printf("USR2 signal kiküldve a (PID: %d) processnek!\n",pidint);
    }
    else{

    exit(0);
    }

    }
}
