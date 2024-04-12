#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

int main(void)
{
	listNode data_n;
	listPointer trail, cur, man, woman, man_e, woman_e, concate;

	listPointer first = NULL;
	
	// data input for each node
	FILE *fp;	

	fopen_s(&fp, "input.txt", "r");
	if( fp == NULL )
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	trail = NULL;
	fscanf_s(fp, "%s%s%s", data_n.name, 10, data_n.job, 20, data_n.gen, 5);		
	while( !feof(fp) )
	{
		insert(&first, &trail , data_n);		// insert data first after node x. 
		fscanf_s(fp, "%s%s%s", data_n.name, 10, data_n.job, 20, data_n.gen, 5);
	}
	insert(&first, &trail, data_n);		// insert data first after node x. 
	printf("전체 리스트 \n");
	printList(first);	

	man_e = woman_e = NULL;
	cur = first;
	man = woman = NULL;

	while (cur) {
		if (!strcmp(cur->gen, "남자")) {
			if (man)
				man_e->link = cur;				
			else
				man = cur;
			man_e = cur;
		}
		else {
			if (woman)
				woman_e->link = cur;
			else
				woman = cur;
			woman_e = cur;
		}
		cur = cur->link;
	}
	if(man_e)
		man_e->link = NULL;
	if (woman_e)
		woman_e->link = NULL;

	printf("남자 리스트 \n");
	printList(man);
	printf("\n여자 리스트 \n");
	printList(woman);

	printf("\n합친리스트 \n");
 	concate = concatenate(woman, man);
	printList(concate);

	printf("\ninversed list \n");
	concate = invert(concate);
	printList(concate);

	
	fclose(fp);
	
	return 0;
}

