#include <stdio.h>

typedef unsigned long long long_t;

/* 콜라츠 수열의 길이를 리턴한다. */
long_t len_collatz(long_t n){
    long_t cnt=0;
    while(n!=1){
        //printf("%lld\n",n);
        cnt++;
        if(n%2==0) n=n/2;
        else n=n*3+1;
    }
    return cnt;
}

/* 콜라츠 수열에서 나타나는 가장 큰 정수를 리턴한다. */
long_t max_collatz(long_t n){
    long_t maxnum=0;
    while(n!=1){
        //printf("@%lld\n",n);
        if(n>maxnum) maxnum=n;
        if(n%2==0) n=n/2;
        else n=n*3+1;
    }
    return maxnum;
}

int main()
{
    long_t N, M;
    scanf("%llu %llu", &N, &M);
    long_t maxlen = 0, maxval = 0;
    for (long_t i = N; i <= M; i++) {
        long_t len = len_collatz(i);
        if (maxlen < len) {
            maxlen = len;
            maxval = i;
        }
    }
    printf("%llu\n", maxval);
    printf("%llu\n", max_collatz(maxval));
}