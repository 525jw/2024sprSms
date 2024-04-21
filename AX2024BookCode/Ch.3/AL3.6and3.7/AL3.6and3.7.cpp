/*
# Page
    112p 114p/ Chapter 3.(Part2) 14p 19p
    http://155.230.120.231/contest/161/problem/AP.6.1
# Name 
    Minimum Multiplications
    Print Optimal Order
# Description 
    연쇄행렬곱셈, 행렬의 개수 n, 행렬의 크기 배열 d(n+1)
    행렬의 크기는 A1=d0 * d1, A2=d1*d2 ... An=d(n-1)*dn
    교재의 코드와 달리 OJ문제는 각가의 모든 행렬까지 괄호를 표기해야한다
# Input
    [n]
    [d[0]] [d[1]] ... [d[n]]
# Output

# TimeComplexity
    O(n^3)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define INF 0xffff
typedef vector<vector<int>> matrix_t;
//- k를 i에서 j-1까지 d[k] 값을 바꿔가며 d[i-1]*d[k]*d[j] + M[i][k]+M[k+1][j] 의 최솟값을 return
int minimum(int i,int j,int& mink,vector<int>& d,matrix_t& M){
    int minValue=INF,value;
    for(int k=i;k<=j-1;k++){
        value=M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j];
        if(minValue>value){
            minValue=value;
            mink=k;
        }
    }
    return minValue;
}
/*- A_i에서 A_j까지 곱 행렬은 d[i-1]*d[j] 크기이다
- M[i][j]=M[i][k]+M[k+1][j]+d[i-1]*d[j]*d[k] , M은 value 저장하는 matrix
- P[i][j]=k : i에서 J까지의 최적해는 i에서 k까지 괄호 k+1에서 j까지 괄호, P는 solution을 저장하는 matrix*/
int minmult(int n,vector<int> d,matrix_t& P,matrix_t& M){
    
    //index 1번부터 주대각선은 모두 0
    for(int i=1;i<=n;i++){
        M[i][i]=0;
        P[i][i]=0;
    }

    // 상삼각행렬, 행은 n-1까지 연산(n번째는 주대각선이라 0이니)
    for(int diagonal=1;diagonal<=n-1;diagonal++)
        for(int i=1;i<=n-diagonal;i++){
            int j=i+diagonal,k;
            M[i][j]=minimum(i,j,k,d,M);
            P[i][j]=k;
        }
    return M[1][n];
}
//- P를 통해 괄호를 친 행렬곱셈식(solution)을 출력
void order(int i,int j,matrix_t& P,string& s){
    if(i==j)
        s+=string("(")+string("A")+to_string(i)+string(")");
    else{
        int k=P[i][j];
        s+=string("(");
        order(i,k,P,s);
        order(k+1,j,P,s);
        s+=string(")");
    }
}
int main(){ 
    int n; cin>>n;
    vector<int> d(n+1);
    for(int i=0;i<=n;i++)
        cin>>d[i];
    matrix_t M(n+1,vector<int>(n+1,-1));
    matrix_t P(n+1,vector<int>(n+1,-1));

    int res=minmult(n,d,P,M);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(M[i][j]!=-1) cout<<M[i][j]<<' ';
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(P[i][j]!=-1) cout<<P[i][j]<<' ';
        cout<<endl;
    }
    cout<<res<<endl; 

    string s;
    order(1,n,P,s);
    cout<<s;
    return 0;
}