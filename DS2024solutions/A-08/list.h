#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

// linked list
typedef struct listNode *listPointer;
typedef struct listNode {
	char name[10];
	char job[20];
	char gen[5];
	listPointer link;
}listNode;


void insert(listPointer *first, listPointer *x, listNode data);				// insert data into ordered list first after node x
void printList(listPointer first);
listPointer concatenate(listPointer ptrl, listPointer ptr2);
listPointer invert(listPointer lead);


void insert(listPointer *first, listPointer *x, listNode n_data)
{ /* insert a new node with a data into the chain first after node x */
	listPointer temp;
	MALLOC(temp, sizeof(*temp));
	strcpy_s(temp->name, 10, n_data.name);
	strcpy_s(temp->job, 20, n_data.job);
	strcpy_s(temp->gen, 5, n_data.gen);

	if(*first == NULL)  
	{ // add to empty list
		temp->link = NULL;
		*first = temp;
		*x = temp;
	}
	else 
	{ // add to non-empty list
			
		if ( x == NULL ) 
		{ // as a first node
			temp->link = *first;
			*first = temp;
			*x = temp;
		}
		else 
		{ 
			temp->link = (*x)->link;
			(*x)->link = temp;
			*x = temp;
		}

	}
}


void printList(listPointer listp)
{
	int count;
//	printf("The ordered list contains: \n");
	for (count = 1 ; listp; listp = listp->link, count++)
		printf("(%p, %s, %s, %s %p )   %s", listp, listp->name, listp->job, listp->gen, listp->link, count%2 ? "" : "\n");
	printf("\n");
}
listPointer concatenate(listPointer ptrl, listPointer ptr2)
{/* produce a new list that contains the list
ptrl followed by the list ptr2. The
list pointed to by ptrl is changed permanently */
	listPointer temp;
	/* check for empty lists */
	if (!ptrl) return ptr2;
	if (!ptr2) return ptrl;
	/* neither list is empty, find end of first list */
	for (temp = ptrl; temp->link; temp = temp->link);
		/* link end of first to start of second */
	temp->link = ptr2;
	return ptrl;
}

listPointer invert(listPointer lead)
{
	listPointer middle, trail;
	middle = NULL;
	while (lead) {
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;
	}
	return middle;
}
