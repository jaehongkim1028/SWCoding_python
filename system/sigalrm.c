#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

// 2020117066 컴퓨터학부 김재홍
// 7주차 과제 1번

int cnt = 0;

void my_alrm_handler(int signum)
{
    time_t ct;
    struct tm tm;
    ct = time(NULL);
    tm = *localtime(&ct);

    printf("2020117066 컴퓨터학부 김재홍\n");
    printf("%d-%d-%d hour: %d, min: %d, sec: %d\n",
        tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour,
        tm.tm_min, tm.tm_sec);
    cnt++;

    if(cnt < 3)
        alarm(5);
    else
        exit(0);

    

}

int main ()
{
    
    signal( SIGALRM, my_alrm_handler );

    alarm(5);
    while (1) {
        sleep(2);
        //alarm(5);  // SIGALRM을 발생시킴. 

    }


}