#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define spacebar ' '
#define endl '\n'
#define INF 9999999
typedef struct vector<vector<int>> matrix;
int solve(int i,int j,vector<int> d,matrix& M,matrix& P){
    if(M[i][j]!=-1) return M[i][j];
    else if(i==j){ P[i][j]=0; return M[i][j]=0; }
    else{
        int minval=INF;
        for(int k=i;k<j;k++){
            int nowval=solve(i,k,d,M,P)+solve(k+1,j,d,M,P)+d[i-1]*d[j]*d[k];
            minval=(minval>nowval) ? P[i][j]=k,nowval : minval;
        }
        return M[i][j]=minval;
    }
}
void print_matmult_order(int i,int j,matrix& P,int& idx){
    if(i==j)
        cout<<'('<<'A'<<++idx<<')';
    else{
        cout<<'(';
        print_matmult_order(i,P[i][j],P,idx);
        print_matmult_order(P[i][j]+1,j,P,idx);
        cout<<')';
    }
}
int main(){ 
    int n; cin>>n;
    vector<int> d(n+1);
    for(int i=0;i<=n;i++)
        cin>>d[i];
    //cache[i][j]=cache[i][k]+cache[k+1][j]+d[i-1]*d[k]*d[j];
    matrix M(n+1,vector<int>(n+1,-1));
    matrix P(n+1,vector<int>(n+1,-1));

    int res=solve(1,n,d,M,P);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(M[i][j]!=-1) {cout<<M[i][j]; if(j!=n) cout<<spacebar;}
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(M[i][j]!=-1) {cout<<P[i][j]; if(j!=n) cout<<spacebar;}
        cout<<endl;
    }
    cout<<res<<endl; 

    int idx=0;
    print_matmult_order(1,n,P,idx);
    return 0;
}