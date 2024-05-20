#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> col;
long long maxval=-1;
int n;
int cnt;

long long arytoint(){
    string numstr;
    for(int i=1;i<=n;i++)
        numstr+=to_string(col[i]);
    return stoll(numstr);
}
bool promising(int i){
    int k=1;
    bool flag=true;

    while(k<i&&flag){
        // row chk || diagonal chk
        if((col[i]==col[k])||(abs(col[i]-col[k])==i-k))
            flag=false;
        k++;
    }
    return flag;
}
void queens(int i){
    int j;
    if(promising(i)){
        if(i==n){
            cnt++;
            long long curval=arytoint();
            maxval=maxval<curval?curval:maxval;
        }
        else
            for(int j=1;j<=n;j++){
                col[i+1]=j;
                queens(i+1);
            }
    }
}
int main(){
    cin>>n;
    col.resize(n+1,0);
    queens(0);
    cout<<cnt<<endl<<maxval;
    return 0;
}