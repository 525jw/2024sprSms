/*
# Page
    70p / Chapter 2.(Part2) 7p
    http://155.230.120.231/contest/156/problem/AP.4.1
# Name 
    Strassen
# Description 
    스트라센 행렬곱셈
# Input
    
# Output

# TimeComplexity
    O(n^lg7)
*/
#include <iostream>
#include <vector>
using namespace std;
typedef struct vector<vector<int>> matrix_t;
int threshold;
//- strassen 호출 횟수
int cnt;
void mmult(int n,matrix_t A,matrix_t B,matrix_t &C){
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++) 
            for(int k=0;k<n;k++) 
                C[i][j]+=A[i][k]*B[k][j];
}
void madd(int n,matrix_t A,matrix_t B,matrix_t &C){
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++) 
            C[i][j]=A[i][j]+B[i][j];
}
void msub(int n,matrix_t A,matrix_t B,matrix_t &C){
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++) 
            C[i][j]=A[i][j]-B[i][j];
}
void partition(int m,matrix_t M,matrix_t& M11,matrix_t& M12,matrix_t& M21,matrix_t& M22){
    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            M11[i][j]=M[i][j];
            M12[i][j]=M[i][j+m];
            M21[i][j]=M[i+m][j];
            M22[i][j]=M[i+m][j+m];
        }
    }
}
void combine(int m,matrix_t &M,matrix_t M11,matrix_t M12,matrix_t M21,matrix_t M22){
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            M[i][j]=M11[i][j];
            M[i][j+m]=M12[i][j];
            M[i+m][j]=M21[i][j];
            M[i+m][j+m]=M22[i][j];
        }
    }
}
void strassen(int n,matrix_t A,matrix_t B,matrix_t &C){
    cnt++;
    if(n<=threshold) 
        mmult(n,A,B,C);
    else{
        matrix_t A11,A12,A21,A22;
        matrix_t B11,B12,B21,B22;
        matrix_t C11,C12,C21,C22;
        matrix_t M1,M2,M3,M4,M5,M6,M7;
        matrix_t L,R;

        int m=n/2;
        A11.resize(m,vector<int>(m));A12.resize(m,vector<int>(m));A21.resize(m,vector<int>(m));A22.resize(m,vector<int>(m));
        B11.resize(m,vector<int>(m));B12.resize(m,vector<int>(m));B21.resize(m,vector<int>(m));B22.resize(m,vector<int>(m));
        C11.resize(m,vector<int>(m));C12.resize(m,vector<int>(m));C21.resize(m,vector<int>(m));C22.resize(m,vector<int>(m));
        L.resize(m,vector<int>(m));R.resize(m,vector<int>(m));
        M1.resize(m,vector<int>(m));M2.resize(m,vector<int>(m));M3.resize(m,vector<int>(m));M4.resize(m,vector<int>(m));
        M5.resize(m,vector<int>(m));M6.resize(m,vector<int>(m));M7.resize(m,vector<int>(m));

        partition(m,A,A11,A12,A21,A22);
        partition(m,B,B11,B12,B21,B22);

        madd(m,A11,A22,L);
        madd(m,B11,B22,R);
        strassen(m,L,R,M1);

        madd(m,A21,A22,L);
        strassen(m,L,B11,M2);

        msub(m,B12,B22,R);
        strassen(m,A11,R,M3);

        msub(m,B21,B11,R);
        strassen(m,A22,R,M4);

        madd(m,A11,A12,L);
        strassen(m,L,B22,M5);

        msub(m,A21,A11,L);
        madd(m,B11,B12,R);
        strassen(m,L,R,M6);

        msub(m,A12,A22,L);
        madd(m,B21,B22,R);
        strassen(m,L,R,M7);

        madd(m,M1,M4,L);
        msub(m,L,M5,R);
        madd(m,R,M7,C11);

        madd(m,M3,M5,C12);
        
        madd(m,M2,M4,C21);

        madd(m,M1,M3,L);
        msub(m,L,M2,R);
        madd(m,R,M6,C22);

        combine(m,C,C11,C12,C21,C22);
    }
}
int main(){
    int n;
    cin >> n >> threshold;

    //n의 값이 2의 거듭제곱 수가 아닐 때에는 n보다 큰 2의 거듭제곱 수를 n으로 재정의해야 한다.
    int k = 1;
    while (k < n) k *= 2;
    int orgN=n; n=k;

    matrix_t A(n,vector<int> (n,0)); 
    matrix_t B(n,vector<int> (n,0));
    matrix_t C(n,vector<int> (n,0));
    int i,j;

    for(i=0;i<orgN;i++) for(j=0;j<orgN;j++) cin>>A[i][j];
    for(i=0;i<orgN;i++) for(j=0;j<orgN;j++) cin>>B[i][j];

    strassen(n,A,B,C);

    cout<<cnt<<endl;
    for(i=0;i<orgN;i++) {
        for(j=0;j<orgN;j++) cout << C[i][j]<< ' ';
        cout<<endl;
    }
    return 0;
}