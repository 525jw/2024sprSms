#include <stdio.h>
char alp[27];
int main(){
	for(int i=0;i<26;i++){
		alp[i]='A'+i;
	}
	char a,b,c;
	int d;
	scanf("%c%c%c%d",&a,&b,&c,&d);
	a=alp[(a-'A'+d)%26];
	b=alp[(b-'A'+d)%26];
	c=alp[(c-'A'+d)%26];
	printf("%c%c%c",alp[a-'A'],alp[b-'A'],alp[c-'A']);
    return 0;
}