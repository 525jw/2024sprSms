#include <stdio.h>

#define MAX 100

int square[MAX][MAX];
void magic(int n);
int main()
{
    int n;
    scanf("%d", &n);
    magic(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", square[i][j]);
        printf("\n");
    }
}
void magic(int n){
    int row=0,col=n/2;
    for(int k=1;k<=n*n;k++){
        square[row][col]=k;
        int trow = (row+n-1)%n;
        int tcol=(col+1)%n;
        if(square[trow][tcol]){
            row=(row+1)%n;
            col=(tcol+n-1)%n;
        }
        else{
            row=trow;
            col=tcol;
        }
    }
}