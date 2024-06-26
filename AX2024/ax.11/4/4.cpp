#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int,vector<int>> graph;
vector<int> mark;
int n,m;
int T;
int s;
int cnt;
void make_graph(int n,int m){
    int imove[]={-2,-1,1,2, 2, 1,-1,-2};
    int jmove[]={ 1, 2,2,1,-1,-2,-2,-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<8;k++){
                int ni=i+imove[k];
                int nj=j+jmove[k];
                if(0<=ni && ni<n && 0<=nj && nj<m){
                    graph[i*m+j].push_back(ni*m+nj);
                }
            }
        }
    }
}
bool finds(int s,vector<int> v){
    for(int i=0;i<v.size();i++){
        if(v[i]==s) return true;
    }
    return false;
}
void tour(int k,int v){
    if(k==n*m && finds(s,graph[v]) ){
        mark[v]=k;
        cnt++;
    }
    else{
        for(int i=0;i<graph[v].size();i++){
            if(mark[graph[v][i]]==0){
                mark[graph[v][i]]=k+1;
                tour(k+1,graph[v][i]);
                mark[graph[v][i]]=0;
            }
        }
    }
}
int main(){
    cin>>n>>m>>T;
    make_graph(n,m);
    mark.resize(n*m,0);
    s=0;
    cnt=0;
    tour(1,s);
    cout<<cnt<<endl;
    while(T--){
        int y,x;
        cin>>y>>x;
        
        s=y*m+x;
        cnt=0;
        mark.clear();
        mark[s]=1;
        tour(1,s);


        cout<<cnt;
        if(T>0) cout<<endl;
    }
}