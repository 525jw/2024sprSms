#include <stdio.h>
int mat[15][15];
int newmat[15][15];
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf(" %d",&mat[i][j]);
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			newmat[i][j]=mat[j][i];
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d",newmat[i][j]);
			if(j<n-1) printf(" ");
		}
		if(i<m-1) printf("\n");
	}
    return 0;
}