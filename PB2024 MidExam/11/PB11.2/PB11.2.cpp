#include <stdio.h>
int S[1000][1000],n,magic;
int chk_diag(){
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=S[i][i];
    if(magic!=sum) return 1;
    sum=0;
    for(int i=0;i<n;i++)
        sum+=S[n-1-i][i];
    return magic!=sum;
}
int check_unique(){
    int count[100005]={0};
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)   
            count[S[i][j]]++;
    for(int i=1;i<=n*n;i++)
        if(count[i]!=1) return 1;
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&S[i][j]);
    for(int i=0;i<n;i++) magic+=S[i][0];
    if(check_unique() || chk_diag()) printf("0");
    else printf("%d",magic);
}