#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <stdlib.h>

int set_ticker(int);
void countdown(int);

int time_interval;
int num;

int main(int argc, char *argv[]){
    time_interval=atoi(argv[1]);
    num=atoi(argv[2]);

    signal (SIGALRM,countdown);
    if(set_ticker(time_interval)==-1)
        perror("set_ticker");
    else
        while(1)
            pause();
    return 0;
}

void countdown(int signum){
    printf("%d .. ",num--);
    fflush(stdout);
    if(num<0){
        printf("DONE!\n");
        exit(0);
    }
}

int set_ticker(int n_msecs){
    struct itimerval new_timeset;
    long n_sec,n_usecs;
    n_sec=n_msecs/1000;
    n_usecs=(n_msecs&1000)*1000L;
    new_timeset.it_interval.tv_sec=n_sec;
    new_timeset.it_interval.tv_usec=n_usecs;
    new_timeset.it_value.tv_sec=n_sec;
    new_timeset.it_value.tv_usec=n_usecs;

    return setitimer(ITIMER_REAL,&new_timeset,NULL);
}