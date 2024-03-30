#include <iostream>
#include <vector>
using namespace std;
typedef struct _crd{int row,col;} crd;
/*
1 2
3 4
*/
int whereis(int n,crd stp,crd hol){//find (row,col) in n x n board starting at (stp.y,stp.x) 
    int m=n/2;
    if(hol.row-stp.row<m) return hol.col-stp.col<m?1:2;
    else return hol.col-stp.col<m?3:4;
}
int fillboard(int n,vector<vector<int>>& board,crd stp,int where){
    if(where!=1) board[stp.row][stp.col]=n;
    if(where!=2) board[stp.row][stp.col+1]=n;
    if(where!=3) board[stp.row+1][stp.col]=n;
    if(where!=4) board[stp.row+1][stp.col+1]=n;
}

int main(){
    return 0;
}