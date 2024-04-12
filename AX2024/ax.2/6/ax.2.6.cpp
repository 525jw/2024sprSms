#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
void collatz(int n,int& col){
    if(n==1) return;
    col++;
    if(n%2==0) collatz(n/2,col);
    else collatz(3*n+1,col);
}
void collatz_print(int n){
    cout << n << ' ';
    if(n==1) return;
    else if(n%2==0) collatz_print(n/2);
    else collatz_print(3*n+1);
}
int main(){
    int n,m,i;
    cin >> n >> m;
    int maxv=-1;
    int col,idx;
    for(i=n;i<=m;i++){
        col=0;
        collatz(i,col);
        if(maxv<col){
            maxv=col;
            idx=i;
        }
    }
    cout << idx << ' ' << maxv << endl;
    collatz_print(idx);
    return 0;
}