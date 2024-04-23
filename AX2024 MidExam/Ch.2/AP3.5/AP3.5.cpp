/*
# Page
    http://155.230.120.231/contest/153/problem/AP.3.5
# Name 

# Description 
    행렬의 거듭제곱
# Input

# Output

# TimeComplexity

*/
#include <iostream>
#include <vector>
#define MODNUM 1000
using namespace std;
//- 행렬의 크기
int n;
//- 거듭제곱의 지수
int b;
vector<vector<int>> matrix_mult(vector<vector<int>> A,vector<vector<int>> B){
    int i,j,k;
    vector<vector<int>> retmat;
    retmat.resize(n,vector<int>(n,0));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                retmat[i][j]+=A[i][k]*B[k][j];
            }
            retmat[i][j]%=MODNUM;
        }
    }
    return retmat;
}
vector<vector<int>> matrix_pow(vector<vector<int>> mat,int pow){
    if(pow==1) return mat;
    else if(pow%2==0) return matrix_mult(matrix_pow(mat,pow/2),matrix_pow(mat,pow/2));
    else return matrix_mult(mat,matrix_mult(matrix_pow(mat,pow/2),matrix_pow(mat,pow/2)));
}
int main(){
    cin >> n >> b;
    vector<vector<int>> mat(n,vector<int> (n));
    int i,j;
    for(i=0;i<n;i++) for(j=0;j<n;j++) cin>>mat[i][j];

    mat=matrix_pow(mat,b);
    
    for(i=0;i<n;i++) {
        for(j=0;j<n-1;j++) cout << mat[i][j] << ' ';
        cout<<mat[i][j]<<endl;
    }
    return 0;
}