#include <stdio.h>
#include <math.h>
#define MAX 10000000

int sieve[MAX + 1];

/* Fill the global variable sieve with 0 or 1.
   The value of sieve[i] should be 1 if i is prime,
   and 0 if i is not prime.
*/
void find_primes();

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    find_primes();
    int cnt = 0;
    for (int i = N; i <= M; i++)
        if (sieve[i]) cnt++;
    printf("%d", cnt);
}

void find_primes(){
    int i,j;
    for(i=2;i<=MAX;i++)
        sieve[i]=1;
    for(i=2;i<=sqrt(MAX);i++)
		if(sieve[i]==1) for(j=2*i;j<=MAX;j+=i) sieve[j]=0;
}