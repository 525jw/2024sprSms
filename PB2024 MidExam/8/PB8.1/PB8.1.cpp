#include <stdio.h>
#include <math.h>

typedef unsigned long long ull_t;

ull_t divsum(ull_t n);

int main()
{
    ull_t N;
    scanf("%llu", &N);
    printf("%llu", divsum(N));
}
ull_t divsum(ull_t n){
	long long i;
	long long sum=0;
	for(i=1;i<=n;i++){
		if(i*i==n){
			sum+=i;
		}
		else if(i*i>n) break;
		else if(n%i==0) sum+=i+(n/i);
	}
	return sum;
}