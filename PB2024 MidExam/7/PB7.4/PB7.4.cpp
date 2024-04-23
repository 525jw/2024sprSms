#include <stdio.h>
int n,m;
void matadd(int n,int m,int matA[][15],int matB[][15],int matC[][15]){
    int i,j;
    for(i=0;i<n;i++) for(j=0;j<m;j++) matC[i][j]=matA[i][j]+matB[i][j];
}
void matsub(int n,int m,int matA[][15],int matB[][15],int matC[][15]){
    int i,j;
    for(i=0;i<n;i++) for(j=0;j<m;j++) matC[i][j]=matA[i][j]-matB[i][j];
}
int main(){
	int matA[15][15];
	int matB[15][15];
	int matC[15][15];
	int matR[15][15];
	scanf("%d %d",&n,&m);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf(" %d",&matA[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf(" %d",&matB[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf(" %d",&matC[i][j]);
		}
	}
	matadd(n,m,matA,matB,matR);
	matsub(n,m,matR,matC,matR);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d",matR[i][j]);
			if(j<m-1) printf(" ");
		}
		if(i<n-1) printf("\n");
	}
    return 0;
}