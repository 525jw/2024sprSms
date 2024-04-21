/*
# Page
    63p 64p/ Chapter 2.(Part1) 25p 26p
    http://155.230.120.231/contest/153/problem/AP.3.4
# Name 
    Quicksort
    Partition
# Description 
    퀵소트
# Input
    [n]
    [S[1]] [S[2]] ... [S[N]]
# Output

# TimeComplexity
    O(nlongn) worst case O(n^2)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//swap 연산의 실행 횟수
int cnt;
int n;
vector<int> S;
void partition(int low, int high, int& pivotpoint) {
    int pivotitem = S[low];
    int j = low;
    for (int i = low+1; i <= high; i++) {
        if (S[i] < pivotitem) {
            j++;
            swap(S[i], S[j]);
            cnt++; // swap 연산의 실행 횟수 카운트
        }
    }
    pivotpoint = j;
    swap(S[low], S[pivotpoint]);
    cnt++; // swap 연산의 실행 횟수 카운트
}
void quicksort(int low,int high){
    int pivotpoint;
    if(low<high){
        partition(low,high,pivotpoint);
        quicksort(low,pivotpoint-1);
        quicksort(pivotpoint+1,high);
    }
}
int main(){
    cin>>n;
    S.resize(n+1);
    for(int i=1;i<=n;i++)
        cin>>S[i];
    quicksort(1,n);
    for(int i=1;i<=n;i++)
        cout<<S[i]<<' ';
    cout<<endl<<cnt;
    return 0;
}