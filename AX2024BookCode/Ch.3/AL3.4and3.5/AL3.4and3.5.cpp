/*
# Page
    103p and 104p/ Chapter 3.(Part1) 37p and 38p
# Name 
    Floyd's Algorithm for Shortest Paths 2
    Print Shortest Path
# Description 
    플로이드 알고리즘을 사용해 최단경로 구하기
    P를 도입해 solution을 알 수 있음
# Input

# Output

# TimeComplexity
    O(nk)
*/
#include <iostream>
#include <vector>
#define INF 0xffff
using namespace std;
typedef struct vector<vector<int>> matrix_t;
void floyd(int n,matrix_t& W,matrix_t& D,matrix_t& P){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            D[i][j]=W[i][j];
            P[i][j]=0;
        }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(D[i][j]>D[i][k]+D[k][j]){
                    D[i][j]=D[i][k]+D[k][j];
                    P[i][j]=k;
                }
            }
}
void path(matrix_t& P,int u,int v,vector<int>& p){
    int k=P[u][v];
    if(k!=0){
        path(P,u,k,p);
        p.push_back(k);
        path(P,k,v,p);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    matrix_t W(n+1,vector<int>(n+1,INF));
    //- 각 vertex에서 다른 vertex로 가는 최단경로
    matrix_t D(n+1,vector<int>(n+1,INF));
    /*- P[i][j]=k : v_i에서 v_j를 가는데 v_k를 거쳐갔다, k는 거쳐간 것 중 가장 높은 index
    - 거쳐간 vertex가 없다면 값은 0*/
    matrix_t P(n+1,vector<int>(n+1,INF));
    int u,v,wgt;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>wgt;
        W[u][v]=wgt;
    }

    //초기화
    for(int i=1;i<=n;i++){
        W[i][i]=0;
        D[i][i]=0;
        P[i][i]=0;
    }

    floyd(n,W,D,P);
    
    //거리 matrix : D출력
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(D[i][j]==INF) cout<<"INF"<<' ';
            else cout<<D[i][j]<<' ';
        }
        cout<<endl;
    }
    //거쳐간vertex matrix : P출력
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<P[i][j]<<' ';
        }
        cout<<endl;
    }
    
    //stp에서 edp까지 가는 경로 vertex를 구한 후 출력
    int t,stp,edp;
    vector<int> p;
    cin>>t;
    while(t--){
        p.clear();
        cin>>stp>>edp;
        if(D[stp][edp]==INF) cout<<"NONE";
        else{
            p.push_back(stp);
            path(P,stp,edp,p);
            p.push_back(edp);
            for(int i=0;i<p.size();i++){
                cout<<p[i]<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}