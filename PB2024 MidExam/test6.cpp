#include <stdio.h>
int visit[20005];
long long collatz(int n){
    if(visit[n]) return 1;
    visit[n]=1;
    if(n==1) return 0;
    if(n%2==0) return collatz(n/2);
    else return collatz(3*n-1);
}
int main(){
    long long n,m,i;
    scanf("%lld%lld",&n,&m);
    long long possible=0;
    for(i=n;i<=m;i++){
        for(int j=0;j<20005;j++) visit[j]=0;
        possible+=collatz(i);
    }
    printf("%lld",possible);
    return 0;
}