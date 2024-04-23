#include <stdio.h>
#include <math.h>

int is_prime(unsigned int n);
unsigned int solve(unsigned int N);

int main()
{
    unsigned int N;
    scanf("%d", &N);
    printf("%X\n", solve(N));
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
unsigned int solve(unsigned int N){
	unsigned int inp;
	unsigned int idx=0;
	unsigned int res=0;
	for(unsigned int i=0;i<N;i++){
		scanf("%u",&inp);
		if(is_prime(inp)) res |= 1<<N-i-1;
	}
	return res;
}