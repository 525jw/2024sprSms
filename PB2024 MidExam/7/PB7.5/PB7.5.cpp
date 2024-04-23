#include <stdio.h>
int n,k,m;
void matmult(long long matA[][15],long long matB[][15],long long matC[][15]){
    int i,j,l;
    for(i=0;i<n;i++) for(j=0;j<m;j++) for(l=0;l<k;l++) matC[i][j]+=matA[i][l]*matB[l][j];
}
int main(){
	long long matA[15][15];
	long long matB[15][15];
	long long matR[15][15]={0,};
	scanf("%d %d %d",&n,&k,&m);
	int i,j,l;
	for(i=0;i<n;i++){
		for(j=0;j<k;j++){
			scanf("%lld",&matA[i][j]);
		}
	}
	for(i=0;i<k;i++){
		for(j=0;j<m;j++){
			scanf("%lld",&matB[i][j]);
		}
	}
	matmult(matA,matB,matR);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%lld",matR[i][j]);
			if(j<m-1) printf(" ");
		}
		if(i<n-1) printf("\n");
	}
    return 0;
}