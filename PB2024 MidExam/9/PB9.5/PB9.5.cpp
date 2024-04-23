#include <stdio.h>
long long cnt=0;
long long ret=-1;
long long ac(long long n,long long m,long long idx){
	cnt++;
	if(n==0) {
		ret=idx>ret?idx:ret;
		return m+1;
	}
	else if(n>0 && m==0) {
		return ac(n-1,1,idx+1);
	}
	else return ac(n-1, ac(n,m-1,idx+1), idx+1);
}
int main(){
	long long n,m;
	scanf("%lld %lld",&n,&m);
	long long idx=1;
	long long ans=ac(n,m,idx);
	printf("%lld\n%lld\n%lld",ans,cnt,ret);
	return 0;
}