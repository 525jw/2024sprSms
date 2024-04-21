/*
# Page
    55p 60p/ Chapter 2.(Part1) 13p 14p
    http://155.230.120.231/contest/153/problem/AP.3.2
# Name 
    Mergesort
    Merge
# Description 
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
//- 정렬에 필요한 extra space 크기
int cnt;
void merge(int h,int m,vector<int> U,vector<int> V,vector<int>& S){
    int i=1,j=1,k=1;

    //i와 j를 증가시키며 값을 S에 저장=U와 V를 합침
    while(i<=h && j<=m)
        S[k++]=(U[i]<V[j]) ? U[i++] : V[j++];

    //U와 V에 남아있는 값을 S에 저장
    if(i>h)
        while(j<=m)
            S[k++]=V[j++];
    else 
        while(i<=h)
            S[k++]=U[i++];
}
void mergesort(int n,vector<int>& S){
    if(n>1){
        int h=n/2,m=n-h;
        vector<int> U(h+1),V(m+1);
        cnt += h + m; // 추가 메모리 크기 카운트. cnt는 전역 변수 메모리 공간을 물어보면 해당 값을 출력
        
        //S[1]에서 S[h]까지를 U[1]에서 U[h]까지로 복사
        for(int i=1;i<=h;i++)
            U[i]=S[i];
        //S[h+1]에서 S[n]까지를 U[h+1]에서 U[n]까지로 복사
        for (int i = h+1; i <= n; i++)
            V[i - h] = S[i];
        mergesort(h, U);
        mergesort(m, V);
        merge(h, m, U, V, S);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> S(n+1);
    for(int i=1;i<=n;i++)
        cin>>S[i];
    mergesort(n,S);
    for(int i=1;i<=n;i++)
        cout<<S[i]<<' ';
    cout<<endl<<cnt;
    return 0;
}