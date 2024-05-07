#include <stdio.h>
int main(){
    char str[4];
    scanf("%s",str);
    int sum=0;
    sum+=str[0]-'0';
    sum+=str[1]-'0';
    sum+=str[2]-'0';
    printf("%d",sum);
    return 0;
}