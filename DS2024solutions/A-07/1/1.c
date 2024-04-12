//  stack - evaluation of postfix expression
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_EXPR_LEN 80

typedef enum {
	lparen, rparen, plus, minus, times, divide,
	mod, eos, operand
} precedence;
/* isp and icp arrays -- index is value of precedence
lparen, rparen, plus, minus, times, divide, mod, eos */
int isp[] = { 0, 19, 12, 12, 13, 13,13, 0 };
int icp[] = { 20, 19, 12, 12, 13, 13,13, 0 };
char expr[MAX_EXPR_LEN]; // postfix expression 
element eval(void);
precedence getToken(char* symbol, int* n);

int main(void)
{
	FILE *fp, *fpP;	


	fopen_s(&fp, "input.txt", "r");
	fopen_s(&fpP, "output.txt", "w");
	if(!fp || !fpP )
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	fgets(expr, MAX_EXPR_LEN, fp);
	printf("postfix expression : %s\n", expr);
	fprintf_s(fpP, "postfix expression : %s\n", expr);
	printf("the evaluation value : %d\n", eval().id);
	fprintf_s(fpP, "the evaluation value : %d\n", eval().id);
	fclose(fpP);

	return 0;
}



element eval(void)
{
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0; /* counter for the expression string */

	element data;
	STACK stack1;
	
	stack_int(&stack1);

	token = getToken(&symbol, &n);
	while( token != eos )
	{
		if (token == operand)
		{
			data.id = symbol - '0';
			if(symbol != ' ')
				 push(&stack1, data); /* stack insert */
		}
			
		else{
			/* pop two operands, perform operation, and 
			push result to the stack */
			op2 = pop(&stack1).id;	/* stack delete */
			op1 = pop(&stack1).id;
			switch(token) {
				case plus:
					data.id = op1 + op2;
					push (&stack1, data);
					break;
				case minus:	
					data.id = op1 - op2;
					push(&stack1, data);
					break;
				case times:	
					data.id = op1 * op2;
					push(&stack1, data);
					break;
				case divide:	
					data.id = op1 / op2;
					push(&stack1, data);
					break;
				case mod:	
					data.id = op1 % op2;
					push(&stack1, data);
			}
		}
		token = getToken( &symbol, &n);
	}
	return pop(&stack1); /* return result */
}

// Program 3.14: Function to get a token from the input string
precedence getToken(char *symbol, int *n)
{ /* get the next token, symbol is the character representation, 
	whichis returned, the tokenis represented by its enumerated value, 
	which is returned inthe function name */
	*symbol = expr[ (*n)++ ];
	switch ( *symbol) 
	{
			case '('		: return lparen;
			case ')'		:  return rparen;
			case '+'		: return plus;
			case '-'		: return minus;
			case '/'		: return divide;
			case '*'		: return times;
			case '%'	: return mod;
			case '\0'	: return eos;
			default		: return operand; /* no error checking, default is operand */
	}
}
