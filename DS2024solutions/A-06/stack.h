#define MAX_STACK_SIZE 100
#define MAX_ROW_SIZE 10
#define MAX_COL_SIZE 10

typedef struct {
	short int row;
	short int col;
	short int dir;
}element;

typedef struct {	
	int top;
	element item[MAX_STACK_SIZE];
} STACK;


void stack_int(STACK* stack);
void push(STACK *stack, element info);
void stackFull(STACK stack);
element pop(STACK* stack);
void sprint(STACK stack);
int isempty(STACK stack);


void stack_init(STACK* stack)
{
	stack->top = -1;
	return;
}

element pop(STACK* stack)
{/* delete and return the top element from the stack */
	if ( stack->top == -1 ) // stack is empty
		{
			fprintf(stderr, "stack is empty, cannot delete element.\n");
			exit(EXIT_FAILURE);
		}
	else
		return stack->item[(stack->top)--] ;
}


void push(STACK* stack, element info)
{/* add an item to the global stack */
	if ( stack->top >= MAX_STACK_SIZE-1 )
		stackFull(*stack);
	stack->top++;
	stack->item[stack->top] = info;
}

void stackFull(STACK stack)
{

	element info;

	fprintf(stderr, "stack is full, cannot add element\n");
	printf("current stack elements : \n");
	for (stack.top; stack.top > -1; stack.top--)
	{
		info = stack.item[stack.top];
		printf("%d %d %d\n", info.row, info.col, info.dir);
	}

	exit(EXIT_FAILURE);
}

void sprint(STACK stack)
{
	int i = 0;
	for (; i <= stack.top; i++)
		printf("%2d%5d\n", stack.item[i].row, stack.item[i].col);

}

int isempty(STACK stack)
{
	if (stack.top >= 0)
		return 1;
	else 
		return 0;
}
