#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct _element{
    int weight;
    int profit;
    int key;
}element;
struct compare{
    bool operator()(const element& a,const element& b){
        return a.key<b.key;
    }
};
priority_queue<element,vector<element>,compare> pq;
int main(){
    int n;
    cin>>n;
    vector<int> w(n);
    vector<int> p(n);
    for(int i=0;i<n;i++)
        cin>>w[i];
    for(int i=0;i<n;i++)
        cin>>p[i];
    for(int i=0;i<n;i++)
        pq.push({w[i],p[i],p[i]/w[i]});
    int T; 
    cin>>T;
    priority_queue<element,vector<element>,compare> temp=pq;
    vector<element> selected;
    for(int i=0;i<T;i++){
        selected.clear();
        temp=pq;
        int W; cin>>W;
        int res=0;

        while(W){
            if(temp.size()==0) break;
            if(W<temp.top().weight){
                res+=W*temp.top().key;
                selected.push_back({W,W*temp.top().key,W*temp.top().key});
                W=0;
                temp.pop();
            }
            else{
                res+=temp.top().profit;
                W-=temp.top().weight;
                selected.push_back(temp.top());
                temp.pop();
            }
        }
        cout<<res<<endl;
        for(int j=0;j<selected.size();j++){
            cout<<selected[j].weight<<' '<<selected[j].profit;
            if(j<selected.size()-1) cout<<endl;
        }
        if(i<T-1) cout<<endl;
    }
    return 0;
}