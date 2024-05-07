#include <stdio.h>
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int max=a>b?(a>c?a:(b>c?b:c)):(b>c?b:c);
	int min=a<b?(a<c?a:(b<c?b:c)):(b<c?b:c);
	printf("%d %d\n",max,min);
	int cnt=0;
	cnt+=a%2?1:0;
	cnt+=b%2?1:0;
	cnt+=c%2?1:0;
	printf("%d %d",cnt,3-cnt);
	return 0;
}