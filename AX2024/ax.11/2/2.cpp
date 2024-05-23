#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int knapsack3(int n,int W,vector<int> w,vector<int> p,map<pair<int,int>,int> &P){
    if(n==0 || W<=0)
        return 0;

    int lvalue=(P.find(make_pair(n-1,W))!=P.end()) ?
        P[make_pair(n-1,W)] : knapsack3(n-1,W,w,p,P);
    int rvalue=(P.find(make_pair(n-1,W-w[n]))!=P.end())?
        P[make_pair(n-1,W-w[n])] : knapsack3(n-1,W-w[n],w,p,P);
    P[make_pair(n,W)]=(w[n]>W)?lvalue:max(lvalue,p[n]+rvalue);
    return P[make_pair(n,W)];
}


int main(){
    vector<int> w,p;
    int n,W;
    cin>>n;
    w.resize(n+1);
    for(int i=1;i<=n;i++)
        cin>>w[i];
    p.resize(n+1);
    for(int i=1;i<=n;i++)   
        cin>>p[i];
    int T;
    cin>>T;
    map<pair<int,int>,int> P;
    while(T--){
        cin>>W;
        P.clear();
        
        cout<<knapsack3(n,W,w,p,P)<<endl;
        int cnt=0;
        for(auto it=P.begin();it!=P.end();it++){
            cout<<(it->first).first<<' '<<(it->first).second<<' '<<it->second;
            cnt++;
            if(cnt!=P.size()) cout<<endl;
        }
        if(T>0) cout<<endl;
    }
    return 0;
}