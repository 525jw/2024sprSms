/*
# Page
    156p / Chapter 4.(part1) 36p
    http://155.230.120.231/contest/164/problem/AP.7.2
# Name 
    Kruskal's Algorithm
# Description 
    n개의 정점과, m개의 간선 그래프의 크루스칼 알고리즘 구현, 각 간선은 가중치 W인 (u,v)
# Input
    [n] [m] 
    [u1] [v1] [W[u1][v1]]
    [u2] [v2] [W[u2][v2]]
    ...
    [um] [vm] [W[um][vm]]
# Output

# TimeComplexity
    O(|E|^2)
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct edge{
    int u,v,w;
}edge_t;
/*- 앞에있는게 parent 뒤에있는게 child
- 반환값이 true이면 swap, 즉 가중치가 작은게 root로*/
struct edge_compare{
    bool operator()(edge_t e1,edge_t e2){
        if(e1.w>e2.w) return true;
        else return false;
    }
};
typedef vector<edge_t> set_of_edges;
/*- priority_queue<자료형, 구현체, 비교 연산자>
- 구현체는 기본적으로 vector<자료형>으로 정의 */
typedef priority_queue<edge_t,vector<edge_t>,edge_compare> PriorityQueue;
/*- union-find 하기위한 벡터 
- dset[p]=q; p의 루트는 q ,
- default 루트는 자기자신*/
vector<int> dset;
void dset_init(int n){
    dset.resize(n+1);
    for(int i=1;i<=n;i++)
        dset[i]=i;
}
int dset_find(int i){
    while(dset[i]!=i)
        i=dset[i];
    return i;
}
void dset_union(int p,int q){
    dset[p]=q;
}
void kruskal(int n,int m,set_of_edges& E,set_of_edges& F){
    int p,q;
    edge_t e;
    PriorityQueue PQ;

    //sort the m edges in E by weight in nondecreasing order;
    for(int i=0;i<E.size();i++)
        PQ.push(E[i]);

    F.clear(); //F=0;
    dset_init(n);
    while(F.size()<n-1){
        e=PQ.top(); PQ.pop();
        p=dset_find(e.u);
        q=dset_find(e.v);
        //p!=q : dset[u]과 dset[v]의 root를 비교해서 cycle이 만들어지는지 체크
        if(p!=q){
            dset_union(p,q);
            F.push_back(e);
        }
    }
}

int main(){
    int n,m,u,v,w;
    cin>>n>>m;
    set_of_edges E,F;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        E.push_back({u,v,w});
    }
    kruskal(n,m,E,F);
    for(int i=0;i<F.size();i++){
        cout<<F[i].u<<' '<<F[i].v<<' '<<F[i].w;
        if(i!=F.size()-1) cout<<endl;
    }
    return 0;
}