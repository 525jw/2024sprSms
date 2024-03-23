#include <iostream>
#include <vector>
using namespace std;
int cnt,n;
vector<int> S;
void merge2(int low, int mid, int high) {
    int i, j, k;
    vector<int> U(high - low + 1);

    i = low; j = mid+1; k = 0;
    while (i <= mid && j <= high) {
        U[k++] = (S[i] < S[j]) ? S[i++] : S[j++];
        cnt++; // S의 원소끼리의 비교 연산 횟수 카운트. cnt는 전역 변수
    }

    if (i > mid)
        while (j <= high) U[k++] = S[j++];
    else
        while (i <= mid) U[k++] = S[i++];
    
    for (int t = low; t <= high; t++)
        S[t] = U[t-low];
}
void mergesort(int left,int right){
    int mid=(left+right)/2;
    if(left<right){
        mergesort(left,mid);
        mergesort(mid+1,right);
        merge2(left,mid,right);
    }
}
int main(){
    cin >> n;
    S.resize(n+1);
    int i;
    for(i=1;i<=n;i++) cin>>S[i];
    mergesort(1,n);
    for(i=1;i<n;i++) cout<<S[i]<<' ';
    cout<<S[i]<<endl<<cnt;
    return 0;
}