#include <iostream>
#include <vector>
using namespace std;
#define INF 9999999
#define spacebar ' '
#define endl '\n'
typedef struct vector<vector<int>> matrix;
int solve(int i,int j,vector<int> prob,matrix& A,matrix& R){
    if(A[i][j]!=-1) return A[i][j];
    else if(i==j) {R[i][j]=0; return A[i][j]=prob[i];}
    else{
        int minval=INF;
        for(int k=i+1;k<j;k++){
            cout<<'#'<<i<<' '<<k-1<<' '<<k+1<<' '<<j<<endl;
            int nowval=solve(i,k-1,prob,A,R)+solve(k+1,j,prob,A,R);
            minval=(minval>nowval) ? R[i][j]=k,nowval : minval;
        }
        for(int k=i;k<=j;k++)
            minval+=prob[k];
        return A[i][j]=minval;
    }
}
int main(){
    int n; cin>>n;
    vector<int> key(n+1),prob(n+1);
    for(int i=1;i<=n;i++)
        cin>>key[i];
    for(int i=1;i<=n;i++)
        cin>>prob[i];
    matrix A(n+1,vector<int>(n+1,-1));
    matrix R(n+1,vector<int>(n+1,-1));

    int res=solve(1,n,prob,A,R);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(A[i][j]!=-1) {cout<<A[i][j]; if(j!=n) cout<<spacebar;}
        cout<<endl;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(R[i][j]!=-1) {cout<<R[i][j]; if(j!=n) cout<<spacebar;}
        cout<<endl;
    }
    cout<<res<<endl; 
    return 0;
}