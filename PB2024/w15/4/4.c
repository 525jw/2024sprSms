#include <stdio.h>
#include <string.h>

void bubblesort(int n, char *ptr[]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            int len1=strlen(ptr[j]);
            int len2=strlen(ptr[j+1]);
            if(len1>len2){
                char t[25];
                strcpy(t,ptr[j]);
                strcpy(ptr[j],ptr[j+1]);
                strcpy(ptr[j+1],t);
            }
            else if(len1==len2){
                if(strcmp(ptr[j],ptr[j+1])>0){
                    char t[25];
                    strcpy(t,ptr[j]);
                    strcpy(ptr[j],ptr[j+1]);
                    strcpy(ptr[j+1],t);
                }
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d\n", &n);
    char str[10][20];
    for (int i = 0; i < n; i++)
        gets(str[i]);
    char *ptr[10];
    for (int i = 0; i < n; i++)
        ptr[i] = str[i];
    bubblesort(n, ptr);
    for (int i = 0; i < n; i++)
        puts(ptr[i]);
}