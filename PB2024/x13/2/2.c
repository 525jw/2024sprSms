#include <stdio.h>

void reverse(int n, int *ptr){
    for(int i=0;i<n/2;i++){
        int temp=ptr[i];
        ptr[i]=ptr[n-i-1];
        ptr[n-i-1]=temp;
    }
}

int main()
{
    int n, arr[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    reverse(n, &arr[0]);
    for (int i = 0;i < n; i++)
        printf("%d ", arr[i]);
}