#define MAX_STACK_SIZE 20
#define MAX_NAME_SIZE 20

typedef enum {
	lparen, rparen, plus, minus, times, divide,
	mod, eos, operand
} precedence;

typedef struct {
	precedence id;												// unique id
	char name[MAX_NAME_SIZE];	// last name
}element;

typedef struct {	
	int top;
	element item[MAX_STACK_SIZE];
} STACK;


void stack_int(STACK* stack);
void push(STACK *stack, precedence info);
void stackFull(STACK stack);
precedence pop(STACK* stack);
precedence peep(STACK* stack);
void sprint(STACK stack);


void stack_int(STACK* stack)
{
	stack->top = -1;
	return;
}

precedence peep(STACK* stack)
{/* delete and return the top element from the stack */
	if (stack->top == -1) // stack is empty
	{
		fprintf(stderr, "stack is empty, cannot delete element.\n");
		exit(EXIT_FAILURE);
	}
	else
		return (stack->item[(stack->top)]).id;
}

precedence pop(STACK* stack)
{/* delete and return the top element from the stack */
	if ( stack->top == -1 ) // stack is empty
		{
			fprintf(stderr, "stack is empty, cannot delete element.\n");
			exit(EXIT_FAILURE);
		}
	else
		return (stack->item[(stack->top)--]).id ;
}


void push(STACK* stack, precedence info)
{/* add an item to the global stack */
	if ( stack->top >= MAX_STACK_SIZE-1 )
		stackFull(*stack);
	stack->top++;
	stack->item[stack->top].id = info;
//	strcpy_s(stack->item[stack->top].name, sizeof(info.name), info.name);

}

void stackFull(STACK stack)
{

	fprintf(stderr, "stack is full, cannot add element\n");
/*
	printf("current stack elements : \n");	
	while( stack.top > -1 )
	{
		
		printf("%d %s\n", stack.item[stack.top].id, stack.item[stack.top].name);
		stack.top--;
	}
*/
	exit(EXIT_FAILURE);
}

void sprint(STACK stack)
{
	element info;

	for (stack.top; stack.top > -1; stack.top--)
	{
		info = stack.item[stack.top];
		printf("%d\n", info.id);
	}
	printf("\n");
}