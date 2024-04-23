#include <stdio.h>
#include <string.h>
int main(){
	unsigned long long cnt_zero=0;
	unsigned long long cnt_one=0;
	unsigned long long n;
	scanf("%llu",&n);
	unsigned long long max=0;
	while(n>1){
		if(n%2) cnt_one++;
		else {
			max=max<cnt_one?cnt_one:max;
			cnt_one=0;
		}
		n/=2;
	}
	if(n%2) cnt_one++;
	max=max<cnt_one?cnt_one:max;
	printf("%llu",max);
    return 0;
}