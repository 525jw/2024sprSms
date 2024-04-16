#include <stdio.h>
#define MAX 100

/* rotates the matix A into the matrix B. */
void rotate(int n, int A[][MAX], int B[][MAX]);

int main()
{
    int n, A[MAX][MAX], B[MAX][MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    rotate(n, A, B);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }
}

void rotate(int n, int A[][MAX], int B[][MAX]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            B[i][j]=A[n-1-j][i];
}