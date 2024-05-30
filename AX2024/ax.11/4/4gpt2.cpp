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
vector<int> start_points;

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

void tour(int k, int v, bool isStartingPoint) {
    if(k==n*m){
        // 모든 정점을 방문한 후, 시작 정점으로 돌아갈 수 있는지 확인
        if (finds(s, graph[v])) {
            cnt++;
        }
        return;
    }
    else{
        for(int i=0;i<graph[v].size();i++){
            if(mark[graph[v][i]]==0){
                mark[graph[v][i]]=k+1;
                tour(k+1,graph[v][i],false);
                mark[graph[v][i]]=0;
            }
        }
    }
}

int main() {
    cin>>n>>m>>T;
    make_graph(n,m);
    mark.resize(n*m,0);
    s=0;
    cnt=0;

    while(T--){
        int y,x;
        cin>>y>>x;
        start_points.push_back(y*m+x);
    }

    for (int i=0;i<start_points.size();i++) {
        s=start_points[i];
        cnt=0;
        fill(mark.begin(),mark.end(),0);
        mark[s]=1;
        tour(1,s,true);
        cout<<cnt;
        if(i<start_points.size()-1) cout<<endl;
    }
}