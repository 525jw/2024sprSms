// doubly linked circular list with a head node
#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"


int main(void)
{
	FILE *fp=NULL;
	nodePointer header = NULL;

	createDLCL( fp, "input.txt", &header);	
	
	printf("After creating a doubly linked circular list with a head node : \n");
	printDLCL( header, forward );
	printDLCL( header, backward );
	
	// delete the nodes with data less than and equl to 50
	deleteDLCL( &header, 50 ); 
	
	printf("After deleting numbers less than and equal to 50 : \n");
	printDLCL( header, 0 ); // 0 : forward
	printDLCL( header, 1 ); // 1 : backword
	
	while (header != header->rlink) {
		header = header->rlink;
		free(header->llink);
	}
	free(header->rlink);
	free(header);

	return 0;
}
