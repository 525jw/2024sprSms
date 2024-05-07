#include <stdio.h>
#define SIZE 100

int *mmax(int n, int m, int *x, int *a, int *b){
    int ret=*x;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //printf("%d\n",*(x+i*SIZE+j));
            if( *(x+i*SIZE+j) > ret){
                ret = *(x+i*SIZE+j);
                *a=i;
                *b=j;
            }
        }
    }
    return x+*a*SIZE+*b;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int A[SIZE][SIZE];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);
    int i, j;
    int *maxptr = mmax(n, m, &A[0][0], &i, &j);
    printf("%d %d %d %d", *maxptr, A[i][j], i, j);
}