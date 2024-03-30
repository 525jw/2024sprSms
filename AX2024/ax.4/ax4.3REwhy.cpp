#include <iostream>
#include <vector>
using namespace std;
typedef struct _crd{int row,col;} crd;
int cnt;
/*
Quadrant
1 2
3 4
*/

//Find (row,col) in n x n board starting at (stp.y,stp.x) 
int whereis(int n,crd stp,crd hol){
    int m=n/2;
    if(hol.row-stp.row<m) return hol.col-stp.col<m?1:2;
    else return hol.col-stp.col<m?3:4;
}

void fillboard(int n,vector<vector<int>>& board,crd stp,int where){
    ++cnt;
    if(where!=1) board[stp.row][stp.col]=cnt;
    if(where!=2) board[stp.row][stp.col+1]=cnt;
    if(where!=3) board[stp.row+1][stp.col]=cnt;
    if(where!=4) board[stp.row+1][stp.col+1]=cnt;
}

crd hole(int part,int where,int n,crd stp,crd hol){
    int m=n/2;
    if(part!=where){
        hol={stp.row+m-1,stp.col+m-1}; 
        if(part==2 || part==4) hol.col+=1;
        if(part==3 || part==4) hol.row+=1; 
    }
    return hol;
}

void tromino(int n,vector<vector<int>>& board,crd stp,crd hol){
    int where=whereis(n,stp,hol); //cout<<"hol is in "<<where<<endl;
    if(n==2)//Exit condition
        fillboard(n,board,stp,where);
    else{
        int m=n/2;
        //Fill in the middle 4 spaces
        fillboard(n,board,{stp.row+m-1,stp.col+m-1},where);
        //Filled spaces are considered holes.                  
        crd newhol;
        newhol=hole(1,where,n,stp,hol);
        tromino(m,board,stp,newhol);
        newhol=hole(2,where,n,stp,hol);
        tromino(m,board,{stp.row,stp.col+m},newhol);
        newhol=hole(3,where,n,stp,hol);
        tromino(m,board,{stp.row+m,stp.col},newhol);
        newhol=hole(4,where,n,stp,hol);
        tromino(m,board,{stp.row+m,stp.col+m},newhol);
    }
}
int main(){
    int n,row,col,i,j;
    cin>>n>>row>>col;
    vector<vector<int>> board(n,vector<int> (n,0));
    tromino(n,board,{0,0},{row,col});
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j<n-1) cout<<board[i][j]<<' ';
            else cout<<board[i][j];
        }
        if(i<n-1) cout<<endl; 
    }
    return 0;
}