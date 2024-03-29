#include <iostream>
#include <vector>
using namespace std;
typedef struct vector<vector<int>> matrix;
int threshold,cnt;
void matmult(int n,matrix matA,matrix matB,matrix &matC){
    int i,j,k;
    for(i=0;i<n;i++) for(j=0;j<n;j++) for(k=0;k<n;k++) matC[i][j]+=matA[i][k]*matB[k][j];
}
void matadd(int n,matrix matA,matrix matB,matrix &matC){
    int i,j;
    for(i=0;i<n;i++) for(j=0;j<n;j++) matC[i][j]=matA[i][j]+matB[i][j];
}
void matsub(int n,matrix matA,matrix matB,matrix &matC){
    int i,j;
    for(i=0;i<n;i++) for(j=0;j<n;j++) matC[i][j]=matA[i][j]-matB[i][j];
}
void partition(int m,matrix mat,matrix& mat11,matrix& mat12,matrix& mat21,matrix& mat22){
    int i,j;
    for(i=0;i<m;i++) {
        for(j=0;j<m;j++) {
            mat11[i][j]=mat[i][j];
            mat12[i][j]=mat[i][j+m];
            mat21[i][j]=mat[i+m][j];
            mat22[i][j]=mat[i+m][j+m];
        }
    }
}
void combine(int m,matrix &mat,matrix mat11,matrix mat12,matrix mat21,matrix mat22){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            mat[i][j]=mat11[i][j];
            mat[i][j+m]=mat12[i][j];
            mat[i+m][j]=mat21[i][j];
            mat[i+m][j+m]=mat22[i][j];
        }
    }
}
void strassen(int n,matrix matA,matrix matB,matrix &matC){
    cnt++;
    if(n<=threshold) matmult(n,matA,matB,matC);
    else{
        matrix A11,A12,A21,A22;
        matrix B11,B12,B21,B22;
        matrix C11,C12,C21,C22;
        matrix M1,M2,M3,M4,M5,M6,M7;
        matrix left,right;
        int m=n/2;

        A11.resize(m,vector<int>(m));A12.resize(m,vector<int>(m));A21.resize(m,vector<int>(m));A22.resize(m,vector<int>(m));
        B11.resize(m,vector<int>(m));B12.resize(m,vector<int>(m));B21.resize(m,vector<int>(m));B22.resize(m,vector<int>(m));
        C11.resize(m,vector<int>(m));C12.resize(m,vector<int>(m));C21.resize(m,vector<int>(m));C22.resize(m,vector<int>(m));
        left.resize(m,vector<int>(m));right.resize(m,vector<int>(m));
        M1.resize(m,vector<int>(m));M2.resize(m,vector<int>(m));M3.resize(m,vector<int>(m));M4.resize(m,vector<int>(m));
        M5.resize(m,vector<int>(m));M6.resize(m,vector<int>(m));M7.resize(m,vector<int>(m));

        partition(m,matA,A11,A12,A21,A22);
        partition(m,matB,B11,B12,B21,B22);

        matadd(m,A11,A22,left);
        matadd(m,B11,B22,right);
        strassen(m,left,right,M1);

        matadd(m,A21,A22,left);
        strassen(m,left,B11,M2);

        matsub(m,B12,B22,right);
        strassen(m,A11,right,M3);

        matsub(m,B21,B11,right);
        strassen(m,A22,right,M4);

        matadd(m,A11,A12,left);
        strassen(m,left,B22,M5);

        matsub(m,A21,A11,left);
        matadd(m,B11,B12,right);
        strassen(m,left,right,M6);

        matsub(m,A12,A22,left);
        matadd(m,B21,B22,right);
        strassen(m,left,right,M7);

        matadd(m,M1,M4,left);
        matsub(m,left,M5,right);
        matadd(m,right,M7,C11);

        matadd(m,M3,M5,C12);
        
        matadd(m,M2,M4,C21);

        matadd(m,M1,M3,left);
        matsub(m,left,M2,right);
        matadd(m,right,M6,C22);

        combine(m,matC,C11,C12,C21,C22);
    }
}
int main(){
    int n;
    cin >> n >> threshold;

    int k = 1;
    while (k < n) k *= 2;
    int orgN=n; n=k;

    matrix matA(n,vector<int> (n,0)); 
    matrix matB(n,vector<int> (n,0));
    matrix matC(n,vector<int> (n,0));
    int i,j;

    for(i=0;i<orgN;i++) for(j=0;j<orgN;j++) cin>>matA[i][j];
    for(i=0;i<orgN;i++) for(j=0;j<orgN;j++) cin>>matB[i][j];

    strassen(n,matA,matB,matC);

    cout<<cnt<<endl;
    for(i=0;i<orgN;i++) {
        for(j=0;j<orgN-1;j++) cout << matC[i][j]<< ' ';
        if(i!=orgN-1) cout<<matC[i][j]<<endl;
        else cout<<matC[i][j];
    }
    return 0;
}