// doubly linked circular list with a head node
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0



//#define COMPARE(x, y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)
#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}


typedef enum direction { forward, backward }direction;

// doubly linked circular list
typedef struct node *nodePointer;
typedef struct node{
	nodePointer llink;
	int data;
	nodePointer rlink;
}node;

void dinsert(nodePointer node, nodePointer newnode);
void ddelete(nodePointer node, nodePointer deleted);
void createDLCL( FILE *fp, char *filename, nodePointer *header);
void printDLCL( nodePointer header, direction dir );
void deleteDLCL(nodePointer * pHeader, int delValue);



// Program 4.26 : Insertion into a doubly linked circular list
void dinsert(nodePointer node, nodePointer newnode)
{ /* insert newnode to the right of node */
	newnode->llink = node;
	newnode->rlink = node->rlink;
	node->rlink->llink = newnode;
	node->rlink = newnode;
}

// Program 4.27: Deletion from a doubly linked circular list
void ddelete(nodePointer node, nodePointer deleted)
{ /* delete from the doubl linked list */
	if(node == deleted)
	{
		printf("Deletion of header node not permitted.\n");
	}
	else
	{
		deleted->llink->rlink = deleted->rlink;
		deleted->rlink->llink = deleted->llink;
		free(deleted);
	}
}

// create a doubly linked circular list with a head
void createDLCL( FILE *fp, char *filename, nodePointer *header)
{
	nodePointer newnode;


	if (fopen_s(&fp, filename, "r"))
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	// Figure 4.22: Empty doubly linked circular list with header node
	MALLOC(*header, sizeof(struct node));
	(*header)->llink = (*header)->rlink = *header;

	
	MALLOC(newnode, sizeof(struct node));  // first node
	fscanf_s(fp, "%d", &newnode->data);		
	while( !feof(fp) )
	{		
		dinsert((*header)->llink, newnode);  // header node's llink is used as last pointer
		MALLOC(newnode, sizeof(struct node));
		fscanf_s(fp, "%d", &newnode->data);		
	}

	fclose(fp);	
}

void printDLCL( nodePointer header, direction dir )
{
	nodePointer temp;
	int count;

	if( header  )
	{
		if ( dir == forward )
		{
			printf("forward\n");
			temp = header->rlink;		// first pointer
			count = 0;
			while(temp != header)
			{
				count++;
				printf("(%p %5d %p) %s", temp->llink,  temp->data, temp->rlink, (count%4 == 0)? "\n": "  ");
				temp = temp->rlink;			
			}
			printf("%s", (count%10 == 0) ? "\n" : "\n\n"); 
		}
		else // backward
		{
			printf("backward\n");
			temp = header->llink;		// last pointer
			count = 0;
			while(temp != header)
			{
				count++;
				printf("(%p %5d %p) %s", temp->llink, temp->data, temp->rlink, (count% 4 == 0) ? "\n" : "  ");
				temp = temp->llink;			
			}
			printf("%s", (count%10 == 0) ? "\n" : "\n\n"); 
		}// if else
	}// if
}

void deleteDLCL(nodePointer * pHeader, int delValue)
{
	nodePointer temp, del;

	if( *pHeader )
	{
			temp = (*pHeader)->rlink;		// first pointer
			while(temp != *pHeader)
			{
				del = temp;
				temp = temp->rlink;	

				if ( del->data <= delValue )
					ddelete(*pHeader, del);
			}
	}
}