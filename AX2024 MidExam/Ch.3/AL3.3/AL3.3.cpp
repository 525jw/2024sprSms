/*
# Page
    102p / Chapter 3.(Part1) 34p
# Name 
    Floyd's Algorithm for Shortest Paths
# Description 
    플로이드 알고리즘을 사용해 최단경로 구하기
    거리만 구할 수 있음, 즉 최적값만 구할 수 있음
# Input

# Output

# TimeComplexity
    O(nk)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0xffff
using namespace std;
typedef struct vector<vector<int>> matrix_t;
void floyd(int n,matrix_t& W,matrix_t& D){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            D[i][j]=W[i][j];
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
}
int main(){
    int n,m;
    cin>>n>>m;
    matrix_t W(n+1,vector<int>(n+1,INF));
    //- 각 vertex에서 다른 vertex로 가는 최단경로
    matrix_t D(n+1,vector<int>(n+1,INF));
    int u,v,wgt;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>wgt;
        W[u][v]=wgt;
    }

    //초기화
    for(int i=1;i<=n;i++){
        W[i][i]=0;
        D[i][i]=0;
    }

    floyd(n,W,D);
    
    //거리 matrix : D출력
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(D[i][j]==INF) cout<<"INF"<<' ';
            else cout<<D[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}