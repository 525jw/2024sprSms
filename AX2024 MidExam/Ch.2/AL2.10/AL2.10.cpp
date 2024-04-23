/*
# Page
    77p / Chapter 2.(Part2) 38p
# Name 
    Large Integer Multiplication 2
# Description 
    큰 수 곱셈 : 카라추바 알고리즘
# Input
    
# Output

# TimeComplexity
    O(n^lg3)
*/
#include <iostream>
#include <vector>
using namespace std;
typedef long long largeint;
int threshold,cnt;
//- 10^m만큼 나누는 함수
largeint div_by_exp(largeint u, int m) {
    for(int i=0;i<m;i++)
        u/=10;
    return u;
}
// - 10^m만큼 곱하는 함수
largeint pow_by_exp(largeint u, int m) {
    for(int i=0;i<m;i++)
        u*=10;
    return u;
}
// - 10^m만큼 나눈 나머지를 구하는 함수
largeint rem_by_exp(largeint u, int m) {
    int d=1;
    for(int i=0;i<m;i++)
        d*=10;
    return u%d;
}
//자릿수 구해주는 함수
int digits(largeint n) {
    if (n == 0) return 1;
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}
/*- uv= xw*10^2m + ((x+y)(w+z)-(xw+yz))*10^m + yz 
- uv= p*10^2m + (r-p-q)*10^m + q*/
largeint karatsuba(largeint u,largeint v){
    cnt++;
    //cout<<u<<' '<<v<<endl;
    largeint x,y,w,z,p,q,r;
    //- 자릿수
    int n=max(digits(u),digits(v));
    if(u==0 || v==0)
        return 0;
    else if(n<=threshold)
        return u*v;
    else{
        //karatsuba를 3번 호출 즉 재귀호출이 3번
        int m=n/2;
        x=div_by_exp(u,m); y=rem_by_exp(u,m);
        w=div_by_exp(v,m); z=rem_by_exp(v,m);
        //cout<<'@'<<x<<' '<<y<<' '<<w<<' '<<z<<endl;
        r=karatsuba(x+y,w+z);
        p=karatsuba(x,w);
        q=karatsuba(y,z);
        //cout<<'#'<<p<<' '<<q<<' '<<r<<endl;
        return pow_by_exp(p,2*m)+pow_by_exp(r-p-q,m)+q;
    }
}
int main(){
    cin>>threshold;

    largeint u,v,r;

    cin>>u>>v;
    r=karatsuba(u,v);

    cout << cnt << endl;
    cout<<r;

    return 0;
}