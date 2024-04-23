#include <stdio.h>
unsigned long long fibo(unsigned long long n){
	if(n<=1) return n;
  	else{
    	return fibo(n-1)+fibo(n-2);
    }
}
int main(){
  	unsigned long long inp;
  	scanf("%llu",&inp);
	printf("%llu",fibo(inp));
}