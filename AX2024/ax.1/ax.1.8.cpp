#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    sort(v.begin()+1,v.end());
    cout << *(v.begin()+1) << ' ' << v[(n+1)/2] << ' ' << v[n];
    return 0;
}