#include <sys/types.h>
#include <utmp.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "utmplib.h"

#define SHOWHOST
 
void show_info(struct utmp*);
void showtime(time_t);
 
int main(){
    struct utmp *utbufp,*utmp_nest();
    if(utmp_open(UTMP_FILE)==0){
        perror(UTMP_FILE);
        exit(1);
    }
    while((utbufp=utmp_next())!=((struct utmp*)NULL))
        show_info(utbufp);
    utmp_close();
    return 0;
}
 
void showtime(long timeval)
{
    char *cp;
    cp=ctime(&timeval);
    printf("%12.12s",cp+4);
}
void show_info(struct utmp *utbufp){
    if (utbufp->ut_type != USER_PROCESS)
        return;
    printf("%-8.8s",utbufp->ut_name);
    printf(" ");
    printf("%-8.8d",utbufp->ut_time);
    showtime(utbufp->ut_time);
#ifdef SHOWHOST
    if(utbufp->ut_host[0]!='\0')
        printf(" (%s)",utbufp->ut_host);
#endif
    printf("\n");
}
