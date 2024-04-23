#include <stdio.h>
int main(){
    long long arr1[15];
    long long arr2[15];
    int n;
    scanf(" %d",&n);
    int i;
    for(i=0;i<n;i++)
        scanf(" %lld",&arr1[i]);
    for(i=0;i<n;i++)
        scanf(" %lld",&arr2[i]);
    long long sum=0;
    for(i=0;i<n-1;i++)
        printf("%lld ",arr1[i]+arr2[i]);
    printf("%lld",arr1[n-1]+arr2[n-1]);
    return 0;
}