#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
vector<vector<int>> dp;
string aryA;
string aryB;
string aryC;
int main(){
    cin>>aryA>>aryB;
	int lenA,lenB;
	lenA=aryA.length(); lenB=aryB.length();
    aryA.insert(0,1,'0'); aryB.insert(0,1,'0');
    lenA=aryA.length(); lenB=aryB.length();
    dp.resize(lenA+5,vector<int>(lenB+5,0));
	for(int i=1;i<=lenA;i++){
		for(int j=1;j<=lenB;j++){
			if(aryA[i]==aryB[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]= dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
        }
    }
    // for(int i=0;i<lenA;i++){
	// 	for(int j=0;j<lenB;j++){
	// 		printf("%d",dp[i][j]);
	// 	}
    //     printf("\n");
	// }
	printf("%d",dp[lenA-1][lenB-1]);
    int i=lenA,j=lenB;
    while(i>0 && j>0) {
        if(dp[i-1][j]==dp[i][j]) i--;
        else if(dp[i][j-1]==dp[i][j]) j--;
        else {
            aryC.push_back(aryA[i]);
            i--;
            j--;
        }
    }
    if(dp[lenA-1][lenB-1]){
        printf("\n");
        for(int i=aryC.size()-1;i>0;i--){
            //if(aryC[i]<'A' || aryC[i]>'Z') printf("#");
            printf("%c",aryC[i]);
        }
    }
    return 0;
}