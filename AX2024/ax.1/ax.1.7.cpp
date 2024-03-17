#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long arr[10001];
    arr[0]=0;
    arr[1]=1;
    int i;
    for(i=2;i<=n;i++){
        arr[i]=(arr[i-1]+arr[i-2])%1000000;
    }
    cout << arr[n];
    return 0;
}