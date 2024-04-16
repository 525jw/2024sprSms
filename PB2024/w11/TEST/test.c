#include <stdio.h>
#define swap(x,y,temp) (temp)=(x),(x)=(y),(y)=(temp)
void bubblesort(int n,int a[]){
    int i,j,temp;
    for(i=0;i<n-1;i++)
        for(j=i;j<n-1-i;j++)
            swap(a[j],a[j+1],temp);
}
int main(){
    int n;
    int a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    bubblesort(n,a);
    for(int i=0;i<n;i++)
        printf("%d",a[i]);
    return 0;
}