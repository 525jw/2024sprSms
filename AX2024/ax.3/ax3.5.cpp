#include <iostream>
#include <vector>
#define MODNUM 1000
using namespace std;
long long n,b;
vector<vector<long long>> matrix_mult(vector<vector<long long>> a,vector<vector<long long>> b){
    long long i,j,k;
    vector<vector<long long>> retmat;
    retmat.resize(n,vector<long long>(n,0));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                retmat[i][j]+=a[i][k]*b[k][j];
            }
            retmat[i][j]%=MODNUM;
        }
    }
    return retmat;
}
vector<vector<long long>> matrix_pow(vector<vector<long long>> mat,long long pow){
    if(pow==1) return mat;
    else {
        vector<vector<long long>> mat_pow=matrix_pow(mat,pow/2);    
        if(pow%2==0) return matrix_mult(mat_pow,mat_pow);
        else return matrix_mult(mat,matrix_mult(mat_pow,mat_pow));
    }
}
int main(){
    cin >> n >> b;
    vector<vector<long long>> mat(n,vector<long long> (n)); 
    int i,j;

    for(i=0;i<n;i++) for(j=0;j<n;j++) cin>>mat[i][j];

    mat=matrix_pow(mat,b);

    for(i=0;i<n;i++) {
        for(j=0;j<n-1;j++) cout << mat[i][j]%MODNUM << ' ';
        cout<<mat[i][j]%MODNUM<<endl;
    }
    return 0;
}