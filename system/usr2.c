#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// 2020117066 컴퓨터학부 김재홍
// 7주차 과제 2번

int usr1_pid;

void check_siguser2(int signum)
{
   
    kill(usr1_pid, SIGUSR1);
    
    exit(0);
    
}

int main(int argc, char *argv[])
{
    // register signal usr1
    signal(SIGUSR2, check_siguser2);
   
    // print my pid
    int my_pid;
    my_pid = getpid();
    printf("pid = %d \n",my_pid);

    // input usr2 pid
    printf("usd1의 pid를 입력하세요. : ");
    scanf("%d", &usr1_pid);


    while(1)
        sleep(1);   
    
    return 0;
}

