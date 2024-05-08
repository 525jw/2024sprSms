#include <iostream>
#include <vector>
using namespace std;
#define INF 1<<64-1
int main(){
    unsigned long long n;
    cin>>n;
    
    vector<unsigned long long> fibnum;
    fibnum.push_back(0); 
    fibnum.push_back(1);
    for(int i=0;fibnum[i]+fibnum[i+1]<=n;i++)
        fibnum.push_back(fibnum[i]+fibnum[i+1]);
    
    vector<unsigned long long> answer;
    for(int i=fibnum.size()-1;n>0||i>=0;i--){
        if(n>=fibnum[i]){
            answer.push_back(fibnum[i]);
            n-=fibnum[i];
        }
    }

    for(int i=answer.size()-2;i>=0;i--){
        cout<<answer[i];
        if(i>0) cout<<endl;
    }
    return 0;
}