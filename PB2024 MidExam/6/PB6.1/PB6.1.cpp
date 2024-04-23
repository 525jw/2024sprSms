#include <stdio.h>
#include <string.h>
int n;
int main(){
	int i,j,k;
	int cnt=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			for(k=j;k<=n;k++){
				if((i+j+k)==n) cnt++;
			}
		}
	}
	printf("%d",cnt);
    return 0;
}