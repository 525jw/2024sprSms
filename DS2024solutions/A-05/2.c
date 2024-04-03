//  Linear queue, Array shift
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define  MAX_LEN  100


void main()
{
	char *delimiter = " \n";	// delimiter for tokenizing
	char *context;
	char *op = NULL;			// addq or deleteq
	element student;
	FILE* fp;
	char line[MAX_LEN];
	QUEUE queue1;


	if (fopen_s(&fp, "input.txt", "r"))
		exit(1);

	queue_int(&queue1);
	while (1)
	{
		if (!fgets(line, MAX_LEN, fp))
			break;

		op = strtok_s(line, delimiter, &context);

		if (!strcmp(op, "add")) // addq
		{
			sscanf_s(op + strlen(op) + 1, "%d%s", &student.id, student.name, (int)sizeof(student.name));
			addq(&queue1, student);
		}
		else if (!strcmp(op, "delete")) // deleteq
			deleteq(&queue1);
		else if (!strcmp(op, "qprint"))
			qprint(queue1);
		else if (!strcmp(op, "quit"))
			break;
		else
			printf("wrong command! try again!\n");
	}// while

}