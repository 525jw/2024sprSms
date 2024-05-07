#include <stdio.h>
char alp[27];
int main(){
	for(int i=0;i<26;i++){
		alp[i]='A'+i;
	}
	char a,b,c;
	scanf("%c%c%c",&a,&b,&c);
	a=alp[(a-'A'+13)%26];
	b=alp[(b-'A'+13)%26];
	c=alp[(c-'A'+13)%26];
	printf("%c%c%c",alp[a-'A'],alp[b-'A'],alp[c-'A']);
    return 0;
}