#include <iostream>
#define MOD 10007
using namespace std;
int cache[300];
int fibo(int n){
    if(cache[n]) return cache[n];
    else if(n==0) return cache[n]=3;
    else{
        int num;
        for(int i=0;i<n;i++){
            num+=(fibo(i)%MOD*fibo(n-i-1)%MOD)%MOD;
        }
        return cache[n]=num%MOD;
    }
}
int main(){
    int n;
    cin>>n;
    cout<<fibo(n);
    return 0;
}