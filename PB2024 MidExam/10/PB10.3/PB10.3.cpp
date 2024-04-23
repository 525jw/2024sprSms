#include <stdio.h>
#include <math.h>

unsigned factor_cnt = 0;
unsigned factors[100];

/*
 * Factorize n and store factors 
 * to the array factors[] in ascending order.
 * factor_cnt should be the number of factors.
 */
void factorize(unsigned n);

int main()
{
    unsigned N;
    scanf("%u", &N);
    factorize(N);
    for (int i = 0; i < factor_cnt; i++)
        printf("%u ", factors[i]);
}
void factorize(unsigned n){
    unsigned i,j;
    for(i=2;i<=sqrt(n);i++){
        while(n%i==0){
            printf("%u ",i);
            n/=i;
        }
    }
    if(n>1) printf("%u",n);
}