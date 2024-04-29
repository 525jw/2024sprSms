#define MAX_STACK_SIZE 10

typedef int element;
element stack[MAX_STACK_SIZE];
int top;

element pop();
void stackFull();
element stackEmpty();
void push(element);


void stackFull()
{
	element item;
	fprintf_s(stderr, "stack is full, cannot add element\n");

	printf_s("current stack elements : \n");
	while (top > -1)
	{
		item = pop();
		printf("%d\n", item);
	}

	exit(EXIT_FAILURE);
}
element pop()
{/* delete and return the top element from the stack */
	if (top == -1)
		return stackEmpty();	/* returns an error key */
	return stack[top--];
}

element stackEmpty()
{
	element item;
	item = -1;  // error key value
	return item;
}

void push(element item)
{/* add an item to the global stack */
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	stack[++top] = item;
}
