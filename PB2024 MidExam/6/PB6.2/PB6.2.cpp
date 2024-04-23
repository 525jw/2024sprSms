#include <stdio.h>
#include <string.h>
int main(){
	unsigned long long cnt_zero=0;
	unsigned long long cnt_one=0;
	unsigned long long n;
	scanf("%llu",&n);
	while(n>1){
		if(n%2) cnt_one++;
		else cnt_zero++;
		n/=2;
	}
			if(n%2) cnt_one++;
		else cnt_zero++;
		printf("%llu\n%llu",cnt_one,cnt_zero);
    return 0;
}