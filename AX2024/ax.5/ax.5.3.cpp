#include <iostream>
#include <vector>
#define INF 999
#define WHITESPACENOOOOOOOOOOOOOOOOO ' '
#define WHEREAREYOUMISSINGENDL '\n'
using namespace std;
typedef struct vector<vector<int>> matrix;
void floyd(int n,matrix& W,matrix& D,matrix& P){
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
void path(matrix& P,int u,int v,vector<int>& p){
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
    matrix W(n+1,vector<int>(n+1,INF));
    matrix D(n+1,vector<int>(n+1,INF));
    matrix P(n+1,vector<int>(n+1,INF));
    int u,v,wgt;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>wgt;
        W[u][v]=wgt;
    }
    for(int i=1;i<=n;i++){
        W[i][i]=0;
        D[i][i]=0;
        P[i][i]=0;
    }
    floyd(n,W,D,P);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<D[i][j];
            if(j!=n) cout<<WHITESPACENOOOOOOOOOOOOOOOOO;
        }
        cout<<WHEREAREYOUMISSINGENDL;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<P[i][j];
            if(j!=n) cout<<WHITESPACENOOOOOOOOOOOOOOOOO;
        }
        cout<<WHEREAREYOUMISSINGENDL;
    }
    
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
                cout<<p[i];
                if(i!=p.size()-1) cout<<WHITESPACENOOOOOOOOOOOOOOOOO;
            }
        }
        if(t!=0) cout<<WHEREAREYOUMISSINGENDL;
    }
    return 0;
}