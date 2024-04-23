#include <stdio.h>

typedef unsigned long long long_t;

long_t solve(long_t n){
    long_t ret=0;
    long_t cnt=0;
    long_t temp=n;
    while(temp){
        cnt++;
        temp/=10;
    }
    long_t ten=1;
    for(int i=0;i<cnt-1;i++){
        ten*=10;
    }
    while(n){
        ret+=(n%10)*ten;
        ten/=10;
        n/=10;
    }
    return ret;
}

int main()
{
    long_t n;
    scanf("%llu", &n);
    printf("%llu", solve(n));    
}