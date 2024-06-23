#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAXARGS 20
#define ARGLEN 100

int execute(char *arglist[]){
    int pid,exitstatus;
    pid=fork();
    switch(pid){
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            execvp(arglist[0],arglist);
            perror("execvp failed");
            exit(1);
        default:
            while(wait(&exitstatus)!=pid)
                ;
    }
}

char *makestring(char *buf){
    char *cp;
    buf[strlen(buf)]='\0';
    cp=malloc(strlen(buf));
    if(cp==NULL){
        fprintf(stderr,"no memory\n");
        exit(1);
    }
    strcpy(cp,buf);
    return cp;
}

int main(){
    char *arglist[MAXARGS+1]={NULL};
    int numargs;
    char *argbuf;
    char *makestring();

    char inpline[MAXARGS*ARGLEN+1];

    while(1){
        printf("$ ");
        fgets(inpline,sizeof(inpline),stdin);
        inpline[strlen(inpline)-1]='\0';

        if(strcmp(inpline,"exit")==0)
            exit(0);

        numargs=0;
        argbuf=strtok(inpline," ");
        while(argbuf!=NULL){
            arglist[numargs++]=makestring(argbuf);
            argbuf=strtok(NULL," ");
        }
        if(numargs>0){
            arglist[numargs]=NULL;
            execute(arglist);
            numargs=0;
        }
    }
    
    return 0;
}