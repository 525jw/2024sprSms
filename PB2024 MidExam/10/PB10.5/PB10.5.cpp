#include <stdio.h>
#include <math.h>
#define MAX 32

/*
 * The function factorize() factorizes n 
 * and store the fequency of factors in the array a[],
 * which is passed by the caller as an argument.
 */
unsigned factorize(unsigned n, unsigned a[]);

int main()
{
    unsigned N, a[MAX];
    scanf("%u", &N);
    unsigned len = factorize(N, a);
    unsigned p = a[0], cnt = 0;
    for (unsigned i = 0; i < len; i++) {
        if (p == a[i]) {
            cnt++;
        } else {
            printf("%u %u\n", p, cnt);
            p = a[i]; cnt = 1;
        }
    }
    printf("%u %u\n", p, cnt);
}
unsigned factorize(unsigned n, unsigned a[]){
    unsigned i,j;
    unsigned idx=0;
    for(i=2;i<=sqrt(n);i++){
        while(n%i==0){
            a[idx++]=i;
            n/=i;
        }
    }
    if(n>1) a[idx++]=n;
    return idx;
}