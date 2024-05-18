#include <iostream>
#include <vector>
using namespace std;

/*
- starts from the index 1
- contains the index of visited noedes
*/
vector<int> vindex;
vector<vector<bool>> W;
int n,m;
int cnt;

bool promising(int i){
    int j;
    bool flag;
    // Check if the last node is not connected to the start node
    if(i==n-1 && !W[vindex[n-1]][vindex[0]])
        flag=false;
    // Check if nodes are not connected
    else if(i>0 && !W[vindex[i-1]][vindex[i]])
        flag=false;
    else{
        flag=true;
        // Check no duplicate nodes are selected
        j=1;
        while(j<i&&flag){
            if(vindex[i]==vindex[j])
                flag=false;
            j++;
        }
    }
    return flag;
}
void hamiltonian(int i){
    int j;

    if(promising(i)){
        // ends when i==n-1 because vindex always contains a starting node
        if(i==n-1)
            cnt++;
        else
            for(j=2;j<=n;j++){
                vindex[i+1]=j;
                hamiltonian(i+1);
            }
    }
}
int main(){
    cin>>n>>m;
    vindex.resize(n);
    W.resize(n+1,vector<bool>(n+1,false));
    int node1,node2;
    for(int i=0;i<m;i++){
        cin>>node1>>node2;
        W[node1][node2]=true;
        W[node2][node1]=true;
    }

    vindex[0]=1;
    hamiltonian(0);

    cout<<cnt;
    return 0;
}