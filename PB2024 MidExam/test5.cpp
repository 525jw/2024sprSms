#include <stdio.h>
#include <math.h>

typedef unsigned long long long_t;

/* n이 소수이면 1, 아니면 0을 리턴한다.*/
long_t is_prime(long_t n);

/* n의 소인수의 합을 리턴한다. */
long_t sum_factors(long_t n);

/* 소인수의 합이 소수가 되는 정수들의 개수를 출력한다. */
long_t solve(long_t n, long_t m);

int main()
{
    long_t N, M;
    scanf("%llu %llu", &N, &M);
    printf("%llu", solve(N, M));    
}

long_t solve(long_t n, long_t m) {
    int cnt = 0;
    for (long_t i = n; i <= m; i++) {
        if (is_prime(sum_factors(i)))
            cnt++;
    }
    return cnt;
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


long_t is_prime(long_t n){
    long_t i,j;
        if(n==1) return 0;
        for(i=2;i<=sqrt(n);i++)
        {
            if(n%i==0) return 0;
        }
        return 1;
    }
