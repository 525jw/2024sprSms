#include <stdio.h>
int main(){
    char a, b;
    scanf("%c %c",&a,&b);
	// read a, b from standard input.
	char c = a ^ b;
	int hd = 0;
	while(c){
		hd+=c&1;
		c=c>>1;
	}
    printf("%d",hd);
	return 0;
}