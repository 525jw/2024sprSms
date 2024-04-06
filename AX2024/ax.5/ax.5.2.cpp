#include <iostream>
#include <vector>
#include <algorithm>
#define MODNUM 10007
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> cache(k+1);
    int i,j;
    for(i=0;i<=n;i++){
        for(j=min(i,k);j>=0;j--){
            if(j==0 || i==j)
                cache[j]=1;
            else
                cache[j]=(cache[j]+cache[j-1])%MODNUM;
        }
    }
    cout<<cache[k];
    return 0;
}