#include <stdio.h>
#include <math.h>

int is_prime(unsigned int n); 
int prime_cnt(int N, int M);

int main()
{
    int N, M;
    scanf("%d %d\n", &N, &M);
    printf("%d\n", prime_cnt(N, M));
}

int prime_cnt(int N, int M){
	int i;
	int cnt=0;
	for(i=N;i<=M;i++){
		if(is_prime(i)) cnt++;
	}
	return cnt;
}
int is_prime(unsigned int n){
	unsigned int i,j;
	if(n==1) return 0;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) return 0;
	}
	return 1;
}