#include <stdio.h>
#define swap(x,y,t) (t)=(x),(x)=(y),(y)=(t)
void reverse(int n,int arr[]){
    for(int i=0;i<n/2;i++){
        int temp;
        swap(arr[i],arr[n-i-1],temp);
    }
}
int main(){
    int arr[]={1,2,3,4,5};
    reverse(5,arr);
    for(int i=0;i<5;i++){
        printf("%d",arr[i]);
    }
    return 0;
}