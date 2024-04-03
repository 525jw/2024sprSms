#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#define  MAX_LEN  100

int main(void)
{
	char *delimiter = " \n";	// delimiter for tokenizing
	char *context;
	char *op = NULL;			// push or pop
	element student;	
	FILE* fp;
	char line[MAX_LEN];

	STACK stack1;


	printf("\n");

	if (fopen_s(&fp, "input.txt", "r"))
		exit(1);

	stack_int(&stack1);
	while (1)
	{
		if (!(fgets(line, MAX_LEN, fp)))
			break;
		op = strtok_s(line, delimiter, &context);

		if (!strcmp(op, "push"))
		{
			sscanf_s(context, "%d %s", &student.id, student.name, (unsigned int)sizeof(student.name));
			push(&stack1, student);
		}
		else if (!strcmp(op, "pop"))
			student = pop(&stack1);
	
		else if (!strcmp(op, "sprint")) {
			sprint(stack1);
			printf("\n");
		}
		else if (!strcmp(op, "quit"))
			break;
		else
			printf("wrong command! try again!\n\n");

	}// while
	fclose(fp);
		
	return 0;
}
