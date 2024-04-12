#include <stdio.h>
#include <math.h>
#define MAX 1000000

int sieve[MAX + 1];

void find_primes();
int count(int n);
void solve(int n);

int main()
{
    int N;
    scanf("%d", &N);
    find_primes();
    solve(N);
}

/* Count the number of primes between 3 and n/2 */
int count(int n) {
    int cnt = 0;
    for (int i = 3; i <= n/2; i++) {
        if (sieve[i] && sieve[n - i])
            cnt++;
    }
    return cnt;
}

void solve(int n) {
    int cnt = count(n);
    int cntnum=0;
    if(cnt>=100) printf("%d",cnt);
    else{
        int i,j;
        for(i=2;i<=n;i++){
            for(j=i;j<=n;j++){
                if(i+j==n && sieve[i] && sieve[j]){
                    printf("%d %d ",i,j);
                    cntnum++;
                    if(cntnum!=cnt) printf("\n");
                }
            }
        }
    }
}

void find_primes(){
    int i,j;
    for(i=2;i<=MAX;i++)
        sieve[i]=1;
    for(i=2;i<=sqrt(MAX);i++)
		if(sieve[i]==1) for(j=2*i;j<=MAX;j+=i) sieve[j]=0;
}