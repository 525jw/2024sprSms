#include <stdio.h>
#include <math.h>
int main(){
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	double ans=(-b+sqrt(b*b-4*a*c))/2/a;
	printf("%.4lf\n",ans);
	ans=(-b-sqrt(b*b-4*a*c))/2/a;
	printf("%.4lf\n",ans);
	return 0;
}