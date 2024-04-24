#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <utmp.h>
#include <fcntl.h>
#include <time.h>

void show_time(long timeval){
    char* cp;
    cp = ctime(&timeval);
    printf("%12.12s",cp+4);
}

void show_info(struct utmp* utbufp){
    printf("%-8.8s",utbufp->ut_name);
    printf(" ");
    printf("%-8.8s",utbufp->ut_line);
    printf(" ");
    show_time(utbufp->ut_time);
#ifdef SHOWHOST
    printf("%s",utbufp->ut_host);
#endif
    printf("\n");
}

int main(){
    struct utmp *utbufp;

    if(utmp_open(UTMP_FILE) == -1){
        perror(UTMP_FILE);
        exit(1);
    }
    while((utbufp = utmp_next()) != (struct utmp*)NULL){
        show_info(utbufp);
    }
    utmp_close();
    return 0;
}