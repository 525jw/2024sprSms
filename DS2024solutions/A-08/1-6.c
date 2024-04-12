#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void)
{
	int data;
	listPointer x, trail, curr, ffirst;
	listPointer first = NULL;


	// data input for each node
	FILE *fp;	
	fopen_s(&fp, "input.txt", "r");
	if( fp == NULL )
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	fscanf_s(fp, "%d", &data);		
	while( !feof(fp) )
	{
		find(first, &x, data);		// find insert position
		insert(&first, x, data);		// insert data first after node x. 
		fscanf_s(fp, "%d", &data);	
	}
	printList(first);	

	curr= ffirst = first;
	trail = NULL;

	while (curr != NULL)
	{
		if (curr->data % 2) {
			x = curr;
			ndelete(&first, trail, x);
			if (ffirst != first) {
				trail = NULL;
				curr = first;
				ffirst = first;
			}
			else
				curr = trail->link;

		}
		else
		 {
			trail = curr;
			curr = curr->link;
		}
	}

	printf("\nAfter deleting nodes with odd value \n\n");
	printList(first);	
	
	fclose(fp);
	
	return 0;
}
