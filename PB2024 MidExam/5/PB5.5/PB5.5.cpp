#include <stdio.h>
int main(){
	int a,b,c,d,e;
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
	if(((a>b) + (a>c) + (a>d) + (a>e))==2) printf("%d",a);
	else if(((b>a) + (b>c) + (b>d) + (b>e))==2) printf("%d",b);
	else if(((d>b) + (d>c) + (d>a) + (d>e))==2) printf("%d",d);
	else if(((c>b) + (c>a) + (c>d) + (c>e))==2) printf("%d",c);
	else if(((e>b) + (e>c) + (e>d) + (e>a))==2) printf("%d",e);
	return 0;
}