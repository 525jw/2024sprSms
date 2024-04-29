// equivalence classes
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}
#define MAX_SIZE 24
#define FALSE 0
#define TRUE 1

// linked list
typedef struct node *nodePointer;
typedef struct node {
	int data;
	nodePointer link;
}node;


int main(void)
{
	short int out[MAX_SIZE];
	nodePointer seq[MAX_SIZE];
	nodePointer x;
	int i, j, n;

	FILE *fp;

	fopen_s(&fp, "input.txt", "r");
	if (!fp)
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	fscanf_s(fp, "%d", &n);
	printf("/* MAX_SIZE of a set S : %d */\n", MAX_SIZE);
	printf("current size of S : %d\n", n);

	for (i = 0; i < n; i++)
	{ /* initialize seq andout */
		out[i] = FALSE;
		seq[i] = NULL;
	}

	printf("S = { ");
	for (i = 0; i < n; i++)
		printf("%d%s ", i, i < n - 1 ? "," : "");
	printf("}\n");

	/* Phase 1: Input the equivalence pairs */
	fscanf_s(fp, "%d%d", &i, &j);
	printf("input pairs : ");



	while (!feof(fp))
	{
		printf("%dR%d ", i, j);
		MALLOC(x, sizeof(*x));
		x->data = j; x->link = seq[i]; seq[i] = x;
		MALLOC(x, sizeof(*x));
		x->data = i; x->link = seq[j]; seq[j] = x;
		fscanf_s(fp, "%d%d", &i, &j);
	}
	printf("\n");
	printf("symmetric 관계 linked List\n");
	for (i = 0; i < n; i++) {
		printf("%d : symmetric 관계: \n", i);
		x = seq[i];
		while (x) {
			printf("(%p %2d %p)   ", x, x->data, x->link);
			x = x->link;
		}
		printf("\n");

	}


	/* Phase 2: Output the equivalence classes */
	for (i = 0; i < n; i++)
	{
		if (out[i] == FALSE)
		{
			printf("\nNew class: %5d", i);
			out[i] = TRUE;				/* set class to true */
			x = seq[i]; top = -1; /* initialize stack */
			for (;;)								/* find rest of class */
			{
				while (x)						/* process list */
				{
					j = x->data;
					if (out[j] == FALSE)
					{
						printf("%5d", j); out[j] = TRUE;
						push(j);
						x = x->link;
						//	y = x->link; x->link = top; top = x; x = y;
					}
					else
					{
						x = x->link;
					}
				} // while

				if (top == -1) break;
				x = seq[pop()];	/* unstack */
			}// for
		}// if
	}// for

	printf("\n");
	fclose(fp);

	return 0;
}