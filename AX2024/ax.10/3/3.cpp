#include <iostream>
#include <vector>
using namespace std;

//- colors are represented as number
vector<int> vcolor;
vector<vector<bool>> W;
int n,k;
int m;
int cnt;

bool promising(int i){
    int j=1;
    bool flag=true;
    //check if two nodes are connected but the same color
    while(j<i && flag){
        if(W[i][j]&&vcolor[i]==vcolor[j])
            flag=false;
        j++;
    }
    return flag;
}
void m_coloring(int i){
    int color;
    if(promising(i)){
        if(i==n)
            cnt++;
        else 
            for(color=1;color<=m;color++){
                vcolor[i+1]=color;
                m_coloring(i+1);
            }
    }
}
int main(){
    cin>>n>>k;
    vcolor.resize(n+1);
    W.resize(n+1,vector<bool>(n+1,false));
    int node1,node2;
    for(int i=0;i<k;i++){
        cin>>node1>>node2;
        W[node1][node2]=true;
        W[node2][node1]=true;
    }

    while(!cnt){
        m_coloring(0);
        m++;
    }
    m--;
    
    cout<<m<<endl<<cnt;
}