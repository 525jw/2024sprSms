/*
# Page
    152p / Chapter 4.(part1) 18p
    http://155.230.120.231/contest/164/problem/AP.7.1
# Name 
    Prim's Algorithm
# Description 
    n개의 정점과, m개의 간선 그래프의 프림 알고리즘 구현, 각 간선은 가중치 W인 (u,v)
    starting_vertex값을 바꿔서 v_1이 시작정점이 아니어도 실행 가능
# Input
    [n] [m] 
    [u1] [v1] [W[u1][v1]]
    [u2] [v2] [W[u2][v2]]
    ...
    [um] [vm] [W[um][vm]]
# Output

# TimeComplexity
    O(|V|^2)
*/
#include <iostream>
#include <vector>
using namespace std;
#define INF 0xffff
typedef vector<vector<int>> matrix_t;
typedef vector<pair<int,int>> set_of_edges;
typedef pair<int,int> edge_t;

//- 시작 vertex의 index, default : 1
const int starting_vertex=1;

void prim(int n,matrix_t& W,set_of_edges& F){
    //- 집합 Y에 속하지 않은 vertex중 Y에 가장 가까운 것의 index, Y는 방문한 vertex의 집합
    int vnear;
    int min;
    //- 집합 Y에 속한 vertex중 v_i와 가장 가까운 것의 index, Y는 방문한 vertex의 집합
    vector<int> nearest(n+1);
    //- 집합 Y에 속한 vertex중 v_i와 가장 가까운 것 사이의 가중치, v_i가 Y에 포함되었으면 distance[i]=-1
    vector<int> distance(n+1);
    
    //초기화
    F.clear();
    for(int i=1;i<=n;i++){
        nearest[i]=starting_vertex;
        distance[i]=W[starting_vertex][i];
    }

    //repeat n-1 times
    int rp=n-1;
    while(rp--){
        //nearest 출력
        for(int i=1;i<=n;i++){
            if(i==starting_vertex) continue;
            cout<<nearest[i]<<' '; 
        }
        cout<<endl;
        
        //Y에 제일 가까운 vertex 찾아서 vnear에 인덱스값 저장
        min=INF;
        for(int i=1;i<=n;i++){
            if(i==starting_vertex) continue;
            if(0<=distance[i] && distance[i]<min){
                min=distance[i];
                vnear=i;
            }
        }
        cout<<'#'<<vnear<<endl;
        // v_nearest[vnear]와 v_vnear 연결 간선을 집합 F에 추가;
        F.push_back(make_pair(vnear,nearest[vnear]));

        //Y에 v_near가 추가된 후 각 vetex와 Y의 distance[i] 갱신
        distance[vnear]=-1;
        for(int i=1;i<=n;i++){
            if(i==starting_vertex) continue;
            if(distance[i]>W[i][vnear]){
                distance[i]=W[i][vnear];
                nearest[i]=vnear;
            }
        }
    }
    //최종 nearest 출력
    for(int i=1;i<=n;i++){
            if(i==starting_vertex) continue;
            cout<<nearest[i]<<' '; 
        }
    cout<<endl;
}

int main(){
    set_of_edges F;
    matrix_t W;
    int n,m,u,v;
    cin>>n>>m;
    
    W.resize(n+1,vector<int>(n+1,INF));
    for(int i=1;i<=n;i++)
        W[i][i]=0;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        cin>>W[u][v];
        W[v][u]=W[u][v];
    }

    prim(n,W,F);
    

    
    for(int i=0;i<F.size();i++){ // edge_t e : F
        edge_t e=F[i];
        u=e.first; v=e.second;
        cout<<u<<" "<<v<<" "<<W[u][v]<<endl;
    }
    return 0;
}