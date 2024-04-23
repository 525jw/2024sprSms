#include <stdio.h>
#include <math.h>

typedef unsigned long long long_t;

/* returns the sum of factors*/
long_t sum_factors(long_t n);

int main()
{
    long_t n, m, maxcnt, maxval;
    scanf("%llu %llu", &n, &m);
    maxcnt = maxval = 0;
    for (long_t i = n; i <= m; i++) {
        long_t s = sum_factors(i);
        if (s > maxcnt) {
            maxcnt = s;
            maxval = i;
        }
    }
    printf("%llu\n", maxval);
    printf("%llu", maxcnt);
}

long_t sum_factors(long_t n){
    long_t i;
    long_t sum=0;
    long_t temp=n;
    for(i=2;i<=sqrt(n);i++){
        while(n%i==0){
            sum+=i;
            n/=i;
        }
    }
    if(n==temp) return 0;
    if(n>1) sum+=n;
    return sum;
}