/*
# Page : 152p / Chapter 4.(part1)
# Name : 
# Description : n+1 크기의 배열S 내에 있는 모든 수를 더하기
# Input :   [n] 
            [S[1]] [S[2]] ... [S[n]]
# Output : [result]
# TimeComplexity : T(n)=n, O(n)
*/
#include <iostream>
#include <vector>
using namespace std;

int sum(int n,vector<int>& S){
    int result=0;
    for(int i=1;i<=n;i++)
        result+=S[i];
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<int> S(n+1);
    for(int i=1;i<=n;i++)
        cin>>S[i];
    int result=sum(n,S);
    cout<<result<<endl;
    return 0;
}