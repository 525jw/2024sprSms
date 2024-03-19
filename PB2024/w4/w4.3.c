#include <stdio.h>
#include <math.h>
int main(){
    char inp;
    scanf("%c",&inp);
    printf("%d\n",inp);
    printf("0x%x\n",inp);
    int cnt=0;
    for(;inp;inp=inp>>1){
        cnt+=(inp&1);
    }
    printf("%d",cnt);
    return 0;
}