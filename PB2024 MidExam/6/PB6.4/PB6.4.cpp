#include <stdio.h>
#include <string.h>
int n;
int main(){
	scanf("%d",&n);
	int odd=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++,odd+=2){
			printf("%d",odd);
			if(j<i) printf(" ");
		}
		printf("\n");
	}
    return 0;
}