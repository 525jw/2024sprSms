#include <stdio.h>
int cnt[27];
int main(){
	int n,i;
    char ch;
    scanf(" %d",&n);
    scanf("%c",&ch);
    for(i=0;i<n;i++){
    	scanf("%c", &ch);
    	if(ch>='A'&&ch<='Z') cnt[ch-'A']++;
	}
	int max=-1;
	for(i=0;i<26;i++){
		max=max>cnt[i]?max:cnt[i];
	}
	for(i=0;i<25;i++){
		if(cnt[i]==max) printf("%d\n",'A'+i);
	}
	if(cnt[25]==max) printf("%d",'A'+i);
	
    return 0;
}
