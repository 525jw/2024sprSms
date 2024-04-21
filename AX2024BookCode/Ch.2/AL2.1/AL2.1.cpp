/*
# Page
    51p/ Chapter 2.(Part1) 6p
    http://155.230.120.231/contest/153/problem/AP.3.1
# Name 
    Binary Search(Recursive)
# Description 
    이진탐색(재귀)
    배열의 개수 N, 탐색하고자 하는 수의 개수 M
# Input
    [N] [M]
    [S[1]] [S[2]] ... [S[N]]
    [X[1]] [X[2]] ... [X[M]]
# Output

# TimeComplexity
    O(logn)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//- 탐색할 수를 저장해 놓은 배열
vector<int> X;
//- 탐색할 수
int x;
//- 탐색을 수행할 배열
vector<int> S;
//- 함수 호출 횟수
int cnt;
//과제에서는 location() 함수라고 표기되어있음
int binsearch2(int low,int high){
    cnt++;
    int mid;
    //종료조건
    if(low>high)
        return 0;
    else{
        mid=(low+high)/2;
        if(x==S[mid])
            return mid;
        else if(x<S[mid])
            return binsearch2(low,mid-1);
        else
            return binsearch2(mid+1,high);
    }
}

int main(){
    int N,M,location;
    cin>>N>>M;
    S.resize(N+1);
    for(int i=1;i<=N;i++)
        cin>>S[i];
    sort(&S[1],&S[N+1]);
    X.resize(M+1);
    for(int i=1;i<=M;i++)
        cin>>X[i];

    for(int i=1;i<=M;i++){
        cnt=0; x=X[i];
        location=binsearch2(1,N);
        cout<<cnt<<' '<<location<<endl;
    }
    return 0;
}