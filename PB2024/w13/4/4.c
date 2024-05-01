#include <stdio.h>

int *find_largest(int n, int *ptr){
    int maxnum=0;
    int* maxptr;
    for(int i=0;i<n;i++){
        if(maxnum<ptr[i]) {
            maxnum=ptr[i];
            maxptr=ptr+i;
        }
    }
    return maxptr;
}

int main()
{
    int n, arr[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int *p = find_largest(n, arr);
    printf("%d", *p);
}