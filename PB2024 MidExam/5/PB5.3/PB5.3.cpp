#include <stdio.h>
int main(){
	char op;
	int op1,op2;
	int res=0;
	scanf("%c %d %d",&op,&op1,&op2);
	switch(op){
		case '+':
			res=op1+op2;
			printf("%d %c %d = %d",op1,op,op2,res);
			break;
		case '-':
			res=op1-op2;
			printf("%d %c %d = %d",op1,op,op2,res);
			break;
		case '*':
			res=op1*op2;
			printf("%d %c %d = %d",op1,op,op2,res);
			break;
		case '/':
			res=op1/op2;
			printf("%d = %d * %d + %d",op1,op2,res,op1%op2);
			break;
	}
	return 0;
}