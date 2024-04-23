/*
# Page
    http://155.230.120.231/contest/161/problem/AP.6.3
# Name 

# Description 
    LCS
# Input

# Output

# TimeComplexity

*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
vector<vector<int>> cache;
string aryA;
string aryB;
string aryC;
int main(){
    //두 문자열 입력
    cin>>aryA>>aryB;
	int lenA,lenB;
	lenA=aryA.length(); lenB=aryB.length();
    aryA.insert(0,1,'0'); aryB.insert(0,1,'0');
    lenA=aryA.length(); lenB=aryB.length();
    cache.resize(lenA+5,vector<int>(lenB+5,0));

    //두 문자열의 LCS 최적 value을 Tabulation으로 계산
	for(int i=1;i<=lenA;i++){
		for(int j=1;j<=lenB;j++){
			if(aryA[i]==aryB[j]) cache[i][j]=cache[i-1][j-1]+1;
            else cache[i][j]= cache[i-1][j] > cache[i][j-1] ? cache[i-1][j] : cache[i][j-1];
        }
    }
    // for(int i=0;i<lenA;i++){
	// 	for(int j=0;j<lenB;j++){
	// 		printf("%d",cache[i][j]);
	// 	}
    //     printf("\n");
	// }


    //value 출력
	printf("%d",cache[lenA-1][lenB-1]);


    //두 문자열의 LCS 최적 solution을 cache table 역추적하여 구하기
    int i=lenA,j=lenB;
    while(i>0 && j>0) {
        if(cache[i-1][j]==cache[i][j]) i--;
        else if(cache[i][j-1]==cache[i][j]) j--;
        else {
            aryC.push_back(aryA[i]);
            i--;
            j--;
        }
    }


    //solution 출력
    if(cache[lenA-1][lenB-1]){
        printf("\n");
        for(int i=aryC.size()-1;i>0;i--){
            //if(aryC[i]<'A' || aryC[i]>'Z') printf("#");
            printf("%c",aryC[i]);
        }
    }
    return 0;
}