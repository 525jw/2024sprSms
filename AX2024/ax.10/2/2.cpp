#include <iostream>
#include <vector>
using namespace std;

int n,W;
//- indicates whether the ith element is included
vector<bool> include;
vector<int> w;
vector<vector<int>> answerlist;

bool promising(int i,int weight,int total){
    return (weight+total>=W) && (weight==W || weight+w[i+1]<=W);
}
/*
- i : index of the current node being considered
- weight : weight of included nodes so far
- total : total weight of the remaining nodes
*/
void sum_of_subsets(int i,int weight,int total){
    if(promising(i,weight,total)){
        if(weight==W){
            vector<int> answer;
            for(int j=1;j<=n;j++)
                if(include[j]) answer.push_back(w[j]);
            answerlist.push_back(answer);
        }
        else{
            include[i+1]=true;
            sum_of_subsets(i+1,weight+w[i+1],total-w[i+1]);
            include[i+1]=false;
            sum_of_subsets(i+1,weight,total-w[i+1]);
        }
    }
}
int main(){
    cin>>n>>W;
    include.resize(n+1,false);
    w.resize(n+1,0);
    int total=0;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        total+=w[i];
    }

    sum_of_subsets(0,0,total);
    
    cout<<answerlist.size();
    if(answerlist.size()){
        cout<<endl;
        for(int i=0;i<answerlist.size();i++){
            for(int j=0;j<answerlist[i].size();j++){
                cout<<answerlist[i][j];
                if(j<answerlist[i].size()-1) cout<<' ';
            }
            if(i<answerlist.size()-1) cout<<endl;
        }
    }
    return 0;
}