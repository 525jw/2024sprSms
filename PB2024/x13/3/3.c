#include <stdio.h>

void reverse(int from, int to, int *ptr){
    for(;from<=to;from++,to--){
        int temp=ptr[from];
        ptr[from]=ptr[to];
        ptr[to]=temp;
    }
}

int main()
{
    int n, from, to, arr[100];
    scanf("%d %d %d", &n, &from, &to);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    reverse(from, to, arr);
    for (int i = 0;i < n; i++)
        printf("%d ", arr[i]);
}