#include <stdio.h>
#include <math.h>

typedef unsigned long long ulong_t;
typedef unsigned int uint_t;

uint_t divcnt(uint_t n);
void solve(uint_t N, uint_t M);

int main()
{
    uint_t N, M;
    scanf("%u %u", &N, &M);
    solve(N, M);
}

uint_t divcnt(uint_t n){
	long long i;
	long long cnt=0;
	for(i=1;i<=n;i++){
		if(i*i>n) break;
		if(n%i==0){
			if(i*i==n) cnt--;
			cnt+=2;
		}
	}
	return cnt;
}
void solve(uint_t N, uint_t M){
	long long i;
	long long max=0;
	long long num=0;
	for(i=N;i<=M;i++){
		long long now=divcnt(i);
		if(max<=now){
			max=now;
			num=i;
		}
	}
	printf("%llu\n",num);
	printf("%llu",max);
}