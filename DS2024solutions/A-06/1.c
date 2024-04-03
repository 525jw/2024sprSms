//  circular queue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_SIZE 20
#define  MAX_LEN  100
#define MALLOC(p, s) \
	if( !( (p) = (element *)malloc( s ) ) ){	\
	fprintf(stderr, "Insufficient memory");\
	exit(EXIT_FAILURE);\
	}

typedef struct {
	int id;												// unique id
	char name[MAX_NAME_SIZE];	// last name
}element;
element *queue;
int capacity = 2;
int rear = 0;
int front = 0;

void addq(element item);
void queueFull();
element deleteq();
element queueEmpty();
void copy(element *a, element *b, element *c);
void qprint();

int main(void)
{

	FILE* fp;
	char line[MAX_LEN];
	char *delimiter = " \n";	// delimiter for tokenizing
	char *context;
	char *op = NULL;			// push or pop
	element student;


	printf("\n");

	MALLOC(queue, capacity * sizeof(*queue));  // Initial capacity is 2.

	if (fopen_s(&fp, "input.txt", "r"))
		exit(1);
	while (1)
	{
		if (!fgets(line, MAX_LEN, fp))
			break;
		op = strtok_s(line, delimiter, &context);

		if (!strcmp(op, "add"))
		{
			sscanf_s(line + strlen(op) + 1, "%d%s", &student.id, student.name, sizeof(student.name));
			addq(student);
		}
		else if (!strcmp(op, "delete"))
		{
			element item = deleteq();

			if (item.id == -1)
			{
				fprintf(stderr, "queue is empty, cannot delete element.\n");
				exit(EXIT_FAILURE);
			}
			else
			{
				//printf("deleted item : %d %s\n", item.id, item.name);
			}
		}
		else if (!strcmp(op, "qprint"))
			qprint();
		else if (!strcmp(op, "quit"))
		{
			printf("end of program!!\n");
			break;
		}
		else
			printf("wrong command! try again!\n");

	} // while
	fclose(fp);
	return 0;
}

// Program 3.9: Add a circular queue
void addq(element item)
{/* add an item to the queue */
	rear = (rear + 1) % capacity;
	if (front == rear) {
		queueFull();		/* double capacity */
		queue[++rear] = item;
		qprint();
		printf("\n");
	}
	else queue[rear] = item;
}

// Program 3.10: Doubling queue capacity
void queueFull()
{
	int start;
	/* allocate an array with twice the capacity */
	element *newQueue;
	MALLOC(newQueue, 2 * capacity * sizeof(*queue));

	/* copy from queue to newQueue */
	start = (front + 1) % capacity;
	if (start < 2)
		/* no wrap around */
		copy(queue + start, queue + start + capacity - 1, newQueue);

	else
	{/* queue wraps around */
		copy(queue + start, queue + capacity, newQueue);
		copy(queue, queue + rear + 1, newQueue + capacity - start);
	}

	/* switch to newQueue */
	front = 2 * capacity - 1;
	rear = capacity - 2;
	capacity *= 2;
	free(queue);
	queue = newQueue;

	printf("queue capacity is doubled,\n");
	printf("current queue capacity is %d.\n", capacity);
}

// Progam 3.8: Delete from a circular queue
element deleteq()
{/* remove front element from the queue */
	if (front == rear)
		return queueEmpty();	/* returns an error key */
	front = (front + 1) % capacity;  // use capacity instead of MAX_QUEUE_SIZE
	return queue[front];
}

element queueEmpty()
{
	element item;
	item.id = -1;  // error key value
	return item;
}

void copy(element *a, element *b, element *c)
{
	while (a != b)
		*c++ = *a++;
}

void qprint()
{
	int i, j;
	if (front > rear)
		j = front + 1 + rear + (capacity - 1 - front);
	else j = rear;
	for (i = front + 1; i <= j; i++)
		printf("%d, %s\n", queue[i%capacity].id, queue[i%capacity].name);
	printf("\n");
}
