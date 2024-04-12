#include <iostream>
using namespace std;
int call=0;
int fib(int n){
    call++;
    if(n==0) return 0;
    if(n==1) return 1;
    return (fib(n-1)+fib(n-2))%1000000;
}
int main(){
    int n;
    cin >> n;
    cout << fib(n) << endl;
    cout << call;
    return 0;
}