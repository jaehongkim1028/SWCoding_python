#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// 2020117066 컴퓨터학부 김재홍
// 7주차 과제 2번

void check_siguser1(int signum)
{
    exit(0);
}

int main(int argc, char *argv[])
{
    // register signal usr1
    signal(SIGUSR1, check_siguser1);
   
    // print my pid
    int my_pid;
    my_pid = getpid();
    printf("pid = %d \n",my_pid);

    // input usr2 pid
    int usr2_pid;
    printf("usd2의 pid를 입력하세요. : ");
    scanf("%d", &usr2_pid);
    // push signal to usr2
    kill(usr2_pid,SIGUSR2);

    
    while(1)
        sleep(1);   
    
    return 0;
}

