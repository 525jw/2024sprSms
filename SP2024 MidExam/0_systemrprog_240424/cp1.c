#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 4096
#define COPYMODE 0644

void oops(char* s1, char* s2){
    fprintf(stderr,"Error %s",s1);
    perror(s2);
    exit(1);
}

int main(int argc, char* argv[]){
    int in_fd, out_fd, n_chars;
    char buf[BUF_SIZE];

    if(argc != 3){
        fprintf(stderr,"usage %s \n",argv[0]);
        exit(1);
    }

    if(in_fd = open(argv[1],O_RDONLY)==-1){
        oops("Cannot open",argv[1]);
    } 
    
    if(out_fd = creat(argv[2],COPYMODE) == -1){
        oops("Cannot create",argv[2]);
    }

    while((n_chars = read(in_fd,buf,BUF_SIZE)) > 0){
        if(write(out_fd,buf,n_chars) != n_chars){
            oops("Write error",argv[2]);
        }
    }
    if(n_chars == -1)   oops("Read error",argv[1]);
    if(close(in_fd) == -1 || close(out_fd) == -1){
        oops("close error","");
    }
}