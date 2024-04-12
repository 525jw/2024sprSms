#include <iostream>
#include <vector>
using namespace std;
int cnt;
void merge(int h,int m, vector<int> U,vector<int> V,vector<int>& S){// h and m are size of U and V, S is merged list of U and V
    int ui=1,vi=1,si=1;
    while(ui<=h && vi<=m){
        if(U[ui]<=V[vi]) S[si++]=U[ui++];
        else S[si++]=V[vi++];
    }
    while(ui<=h) S[si++]=U[ui++];
    while(vi<=m) S[si++]=V[vi++];
}
void mergesort(int n, vector<int>& S) {
    if (n > 1) {
        int h = n / 2, m = n - h;
        vector<int> U(h+1), V(m+1);
        cnt += h + m; // 추가 메모리 크기 카운트. cnt는 전역 변수
        for (int i = 1; i <= h; i++)
            U[i] = S[i];
        for (int i = h+1; i <= n; i++)
            V[i - h] = S[i];
        mergesort(h, U);
        mergesort(m, V);
        merge(h, m, U, V, S);
    }
}

int main(){
    vector <int> list;
    int n;
    cin >> n;
    list.resize(n+1);
    int i;
    for(i=1;i<=n;i++) cin >> list[i];
    mergesort(n,list);
    for(i=1;i<n;i++) cout << list[i] << ' ';
    cout <<list[i]<< endl << cnt ;
    return 0;
}