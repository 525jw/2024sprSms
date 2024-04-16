#include <stdio.h>
#define MAX 1000

int cnt;

/* swaps the elements of a[i] and a[j] */
void swap(int a[], int i, int j);
/* sorts the elements of a[] indexed from 0 to n-1.*/
void bubblesort(int n, int a[]);

int main()
{
    int N, A[MAX];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    
    cnt = 0;
    bubblesort(N, A);
    printf("%d\n", cnt);
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);
}

void bubblesort(int n,int a[]){
    int i,j,temp;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(a[j]>a[j+1]) swap(a,j,j+1);
}

void swap(int a[], int i, int j){
    cnt++;
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}