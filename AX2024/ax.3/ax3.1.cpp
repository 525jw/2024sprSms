#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> list;
int n,m,target,callcnt;
int location(int left,int right){
    callcnt++;
    if(left<=right){
        int mid=(left+right)/2 ;
        if(list[mid]==target) return mid;
        else if(list[mid]>target) return location(left,mid-1);
        else return location(mid+1,right);
    }
    else return 0;
}
int main(){
    cin >> n >> m;
    int i;
    list.resize(n+1);
    for(i=1;i<=n;i++) cin >> list[i];
    sort(list.begin()+1,list.end());
    int loc;
    while(m--){
        cin >> target;
        callcnt=0;
        loc=location(1,list.size()-1);
        cout << callcnt << ' ' << loc;
        if(m>0) cout << endl;
    }
    return 0;
}