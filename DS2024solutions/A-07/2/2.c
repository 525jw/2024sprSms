
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define MAX_EXPR_LEN 80

// infix to postfix

/* isp and icp arrays -- index is value of precedence
lparen, rparen, plus, minus, times, divide, mod, eos */
int isp[] = { 0, 19, 12, 12, 13, 13,13, 0 };
int icp[] = { 20, 19, 12, 12, 13, 13,13, 0 };


void postfix(void);
precedence getToken(char *symbol, int *n);
void printToken(precedence);


// infix expression 
char expr[MAX_EXPR_LEN];
FILE *fpI, *fpP;	// input(infix), output(postfix)

int main(void)
{
	precedence abc, bc;

	fopen_s(&fpI, "input.txt", "r");
	fopen_s(&fpP, "output.txt", "w");

	abc = operand;
	bc = plus;
	printf("abc = %d, bc = %d\n", abc, bc);
	printf("operand = %d, bc = %d\n", operand, plus);

	if (!fpI || !fpP )
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	fgets(expr, MAX_EXPR_LEN, fpI); // input infix expression
	printf("<<<<<<<<<< infix to postfix >>>>>>>>>>>>>\n");
	printf("infix expression\t: %s\n", expr);
	printf("postfix expression\t: ");

	postfix();	// infix to postfix

	fclose(fpI);
	fclose(fpP);

	return 0;
}

void postfix(void)
{
	STACK stack1;
	char symbol;
	precedence token;
	int n = 0;

	stack_int(&stack1);
	push(&stack1, eos);


	for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n))
	{
		if (token == operand)
		{
			printf("%c ", symbol);
			fprintf(fpP, "%c ", symbol);
		}
		else if (token == rparen) {
			/* unstack tokens until left parenthesis */
			while (peep(&stack1) != lparen)
				printToken(pop(&stack1));
			pop(&stack1);	/* discard the left parenthesis */
		}
		else { // operator, lparen
			   /* remove and print symbols whose isp is greater
			   than or equal to the current token's icp */
			while (isp[peep(&stack1)] >= icp[token])
				printToken(pop(&stack1));
			push(&stack1, token);
		}
	}

	while ((token = pop(&stack1)) != eos)
		printToken(token);
	printf("\n");
}

precedence getToken(char *symbol, int *n)
{ /* get the next token, symbol is the character representation,
  whichis returned, the tokenis represented by its enumerated value,
  which is returned inthe function name */
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
	case '(': return lparen;
	case ')':  return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand; /* no error checking, default is operand */
	}
}

void printToken(precedence pre)
{
	switch (pre)
	{
		// in postfix expression, there are no parentheses
	case plus:	printf("%c ", '+');	fprintf_s(fpP, "%c ", '+');	break;
	case minus:	printf("%c ", '-');		fprintf_s(fpP, "%c ", '-');	break;
	case divide:	printf("%c ", '/');		fprintf_s(fpP, "%c ", '/');	break;
	case times:	printf("%c ", '*');	fprintf_s(fpP, "%c ", '*');	break;
	case mod:	printf("%c ", '%');	fprintf_s(fpP, "%c ", '%');	break;
	//case eos		:	printf( "%c ", '\0' );	fprintf( fpP, "%c ", '\0' );	break; // ºÒÇÊ¿ä
	default:  ;	   // operand
	}
}
