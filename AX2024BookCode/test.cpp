#include <iostream>
#define MOD 10007
using namespace std;
int cache[300];
int fibo(int n){
    if(cache[n]) return cache[n];
    else if(n==0) return cache[n]=1;
    else if(n==1) return cache[n]=1;
    else if(n==2) return cache[n]=2;
    else{
        return cache[n]=(fibo(n-1)%MOD+fibo(n-2)%MOD+fibo(n-3)%MOD)%MOD;
    }
}
int main(){
    int n;
    cin>>n;
    cout<<fibo(n);
    return 0;
}