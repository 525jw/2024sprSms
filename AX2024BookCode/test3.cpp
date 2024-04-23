#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;
long long collatz(long long n,long long& col,vector<long long>& visit){
    for(int i=0;i<visit.size();i++){
        if(n==visit[i]) return 1;
    }
    visit.push_back(n);
    if(n==1) return 0;
    col++;
    if(n%2==0) return collatz(n/2,col,visit);
    else return collatz(3*n-1,col,visit);
}
void collatz_print(long long n){
    cout << n << ' ';
    if(n==1) return;
    else if(n%2==0) collatz_print(n/2);
    else collatz_print(3*n+1);
}
int main(){
    long long n,m,i;
    cin >> n >> m;
    long long maxv=-1;
    long long col,idx;
    long long possible=0;
    for(i=n;i<=m;i++){
        col=0;
        vector<long long> visit;
        visit.clear();
        possible+=collatz(i,col,visit);
        if(maxv<col){
            maxv=col;
            idx=i;
        }
    }
    cout<<'#'<<possible<<endl;
    //cout << idx << ' ' << maxv << endl;
    collatz_print(idx);
    return 0;
}