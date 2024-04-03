//  Linear queue, Array shift

#define MAX_QUEUE_SIZE 3
#define MAX_NAME_SIZE 20

typedef struct {
	int id;												// unique id
	char name[MAX_NAME_SIZE];	// last name
}element;

typedef struct {
	int rear, front;
	element item[MAX_QUEUE_SIZE];
} QUEUE;



void queue_int(QUEUE* queue)
{

	queue->front = queue->rear = -1;


}

void qprint(QUEUE queue)
{
	int i;
	i = queue.front;
	for (; i != queue.rear;) {
		i = i + 1;
		printf("%d %s\n", queue.item[i].id, queue.item[i].name);
	}
	printf("\n");
}



int queueEmpty(QUEUE queue)
{
	return (queue.front == queue.rear);
}

int isFull(QUEUE *queue)
{
	int temp, num, i = 0;
	
	if ((queue->rear == MAX_QUEUE_SIZE-1) && (queue->front < 0) )
		return 1;
	if ((queue->rear == MAX_QUEUE_SIZE-1) && (queue->front >= 0)) {
		num = queue->rear - queue->front-1;
		temp = queue->front + 1;
		while (i <= num)
			queue->item[i++] = queue->item[temp++];	
		queue->front = -1;
		queue->rear = num;
		printf("\ndata shift\n");
	}
	
	return 0;
}

void addq(QUEUE* queue, element info)
{
	if (isFull(queue)) {
		printf("\nqueue is full, not added\n");
		return;
	}
	queue->rear++;
	queue->item[queue->rear] = info;
}

element deleteq(QUEUE* queue)
{
	if (queueEmpty(*queue)) {
		fprintf(stderr, "\nqueue is empty, cannot delete element.\n");
		exit(EXIT_FAILURE);
	}
	else {
		queue->front = queue->front + 1;
		return queue->item[queue->front];
	}
}