/*
# Page : 4p
# Name : 순차 탐색
# Description : n+1크기의 배열 S내에서 x가 위치한 인덱스를 탐색 후 location에 저장, S내에 x가 없다면 0을 location에 저장
# Input :   [n] 
            [S[1]] [S[2]] ... [S[n]]
            [x]
# Output : [location]
# TimeComplexity : T(n)=n, O(n)
*/
#include <iostream>
#include <vector>
using namespace std;
typedef int keytype;
typedef int index;

void seqsearch(int n,const keytype S[],keytype x,index& location){
    location=1;
    while(location<=n&&S[location]!=x)
        location++;
    if(location>n)
        location=0;
}

int main(){
    int n,x,location;
    cin>>n;
    vector<int> S(n+1);
    for(int i=1;i<=n;i++)
        cin>>S[i];
    cin>>x;
    int *pS=&S[0];
    seqsearch(n,pS,x,location);
    cout<<location<<endl;
    return 0;
}