/*
# Page
    61p 63p/ Chapter 2.(Part1) 20p 21p
    http://155.230.120.231/contest/153/problem/AP.3.3
# Name 
    Mergesort2
    Merge2
# Description 
    AL2.2and2.3과의 차이는 extra-space sort가 아니라 in-place sort라는 것
    공간복잡도가 절반으로 줄어듦
    합병정렬
    배열의 개수 n
# Input
    [n]
    [S[1]] [S[2]] ... [S[N]]
# Output

# TimeComplexity
    O(nlongn)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int cnt;
vector<int> S;
void merge2(int low, int mid,int high){
    int i=low,j=mid+1,k=0;
    vector<int> U(high-low+1);

    //i와 j를 증가시키며 값을 U에 저장
    while(i<=mid&&j<=high){
        U[k++]=(S[i]<S[j])?S[i++]:S[j++];
        cnt++; // S의 원소끼리의 비교 연산 횟수 카운트. cnt는 전역 변수
    }
    //S에 남아있는 값을 S에 저장
    if(i>mid)
        while(j<=high)
            U[k++]=S[j++];
    else
        while(i<=mid)
            U[k++]=S[i++];
    //merge2의 범위 from low to high만큼 임시변수 U에서 S로 저장 
    for(int t=low;t<=high;t++)
        S[t]=U[t-low];
}
void mergesort2(int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort2(low, mid);
        mergesort2(mid+1, high);
        merge2(low,mid,high);
    }
}

int main(){
    cin>>n;
    S.resize(n+1);
    for(int i=1;i<=n;i++)
        cin>>S[i];
    mergesort2(1,n);
    for(int i=1;i<=n;i++)
        cout<<S[i]<<' ';
    cout<<endl<<cnt;
    return 0;
}