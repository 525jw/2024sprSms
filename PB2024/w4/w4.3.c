#include <stdio.h>
#include <math.h>
int main(){
    int inp;
    scanf("%d",&inp);
    printf("0x%x\n",inp);
    int cnt=0;
    for(;inp;inp=inp>>1){
        cnt+=(inp&1);
    }
    printf("%d",cnt);
    return 0;
}