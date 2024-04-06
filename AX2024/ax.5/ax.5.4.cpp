#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct vector<vector<int>> matrix;
int main(){
    int n;
    cin>>n;
    matrix tgl(n+5,vector<int>(n+5,-1));
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>tgl[i][j];
    matrix org=tgl;

    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++){
            if(i==j) tgl[i][j]+=tgl[i-1][j-1];
            else if(j==1) tgl[i][j]+=tgl[i-1][j];
            else tgl[i][j]+=max(tgl[i-1][j-1],tgl[i-1][j]);
            }


    int idx=1;
    int maxval=-1;
    for(int i=1;i<=n;i++){
        if(maxval<=tgl[n][i]){
            maxval=tgl[n][i];
            idx=i;
        }
    }
    vector<int> res;
    res.push_back(org[n][idx]);
    for(int i=n;i>=1;i--){
        if(idx!=1 && tgl[i-1][idx]<tgl[i-1][idx-1]) res.push_back(org[i-1][--idx]);
        else res.push_back(org[i-1][idx]);
        }
    reverse(res.begin(),res.end());
    cout<<maxval<<endl;
    for(int i=1;i<res.size()-1;i++)
        cout<<res[i]<<' ';
    cout<<res.back();
    return 0;
}