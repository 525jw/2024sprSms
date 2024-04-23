/*
# Page
    163p / Chapter 4.(part1) 47p
    http://155.230.120.231/contest/164/problem/AP.7.3
# Name 
    Dijkstra's Algorithm
# Description 
    n개의 정점과, m개의 간선 그래프의 다익스트라 알고리즘 구현, 각 간선은 가중치 W인 (u,v)
    시작정점부터 T개의 정점으로 가는 최단경로를 각각 출력하기
# Input
    [n] [m] 
    [u1] [v1] [W[u1][v1]]
    [u2] [v2] [W[u2][v2]]
    ... 
    [um] [vm] [W[um][vm]]
    [T]
    [t1]
    [t2]
    ...
    [tT]
# Output

# TimeComplexity
    O(n^2)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0xffff
typedef vector<vector<int>> matrix_t;
typedef vector<pair<int,int>> set_of_edges;
typedef pair<int,int> edge_t;

//- 시작 vertex의 index, default : 1
const int starting_vertex=1;

//dijsktar 실행 후 find_shortest_path에 쓰기 위해 touch 반환
vector<int> dijkstra(int n,matrix_t& W,set_of_edges& F){
    //- 집합 Y에 속하지 않은 vertex중 Y에 가장 가까운 것의 index, Y는 방문한 vertex의 집합
    int vnear;
    int min;
    /*- touch[i] = Y내 vertex만 거쳐 i까지 갈 때 거쳐가는 경로의 마지막 vertex의 index, Y는 이미 거쳐간 vertex 집합
    - 즉 Y내 vertex 중 v_i랑 직접적으로 연결된 vertex*/
    vector<int> touch(n+1);
    //- length[i] = Y내 vertex만 거쳐 시작정점부터 v_i까지 가는 경로 중 최단경로의 길이, v_i가 Y내 포함되었다면 -1
    vector<int> length(n+1);

    //초기화
    F.clear();
    for(int i=1;i<=n;i++){
        if(i==starting_vertex) continue;
        touch[i]=starting_vertex;
        length[i]=W[starting_vertex][i];
    }

    //repeat n-1 times
    int rp=n-1;
    while(rp--){
        //touch 출력
        for(int i=1;i<=n;i++){
            if(i==starting_vertex) continue;
            cout<<touch[i];
            if(i!=n) cout<<' ';
        } cout<<endl;

        //Y에 속하지 않은 vertex로 가는 경로 중 최단 경로를 탐색, 해당 vertex의 index를 vnear에 저장
        min=INF;
        for(int i=1;i<=n;i++){
            if(i==starting_vertex) continue;
            if(0<=length[i]&&length[i]<min){
                min=length[i];
                vnear=i;
            }
        }

        //v_touch[vnear]와 v_vnear 연결간선을 F에 추가
        F.push_back(make_pair(touch[vnear],vnear));

        //Y에 속하지 않은 vertex 중에서 vnear를 거쳐갔을 때 경로가 더 짧아진다면 length 갱신
        for(int i=1;i<=n;i++){
            if(i==starting_vertex) continue;
            if(length[i]>length[vnear]+W[vnear][i]){
                length[i]=length[vnear]+W[vnear][i];
                touch[i]=vnear;
            }
        }
        length[vnear]=-1;
    }
    //최종 touch 출력
    for(int i=1;i<=n;i++){
        if(i==starting_vertex) continue;
        cout<<touch[i];
        if(i!=n) cout<<' ';
    } cout<<endl;
    
    return touch;
}
//- 목적지 정점 v_destination에 대해 touch를 참조하여 시작지점에서의 최단 경로가 저장된 vector 반환
vector<int> find_shortest_path(vector<int>touch,int destination){
    vector<int> path;
    while(1){
        path.push_back(destination);
        if(destination==starting_vertex) break;
        destination=touch[destination];
    }
    reverse(path.begin(),path.end());
    return path;
}
int main(){
    int n,m,u,v,T;
    matrix_t W;
    set_of_edges F;
    cin>>n>>m;
    W.resize(n+1,vector<int>(n+1,INF));
    for(int i=0;i<m;i++){
        cin>>u>>v;
        cin>>W[u][v];
    }

    //T입력, T개의 목적지 정점 입력
    cin>>T;
    vector<int> T_destination; int T_inp;
    for(int i=0;i<T;i++){
        cin>>T_inp;
        T_destination.push_back(T_inp);
    }


    
    vector<int> touch=dijkstra(n,W,F);
    

    for(int i=0;i<F.size();i++)
        cout<<F[i].first<<' '<<F[i].second<<' '<<W[F[i].first][F[i].second]<<endl;
    
    //T개의 정점에 대해 최단경로 출력
    for(int i=0;i<T;i++){
        vector<int> path=find_shortest_path(touch,T_destination[i]);
        for(int j=0;j<path.size();j++){
            cout<<path[j];
            if(j!=path.size()-1) cout<<' ';
        }
        if(i!=T-1) cout<<endl;
    }
    return 0;
}