//  circular queue

#define MAX_QUEUE_SIZE 3
#define MAX_NAME_SIZE 20

typedef struct {
	int id;						// unique id
	char name[MAX_NAME_SIZE];	// last name
}element;

typedef struct {
	int rear, front;
	element item[MAX_QUEUE_SIZE];
} QUEUE;


void qprint(QUEUE queue)
{
	int i;

	i = queue.front;
	for (; i != queue.rear;) {
		i = (i + 1) % MAX_QUEUE_SIZE;
		printf("%d, %s\n", queue.item[i].id, queue.item[i].name);
	}
	printf("\n");
}

void queue_int(QUEUE *queue)
{
	queue->front = queue->rear = 0;
}

int isEmpty(QUEUE queue)
{
	return (queue.front == queue.rear);
}

int isFull(QUEUE queue)
{
	return ((queue.rear + 1) % MAX_QUEUE_SIZE == queue.front);
}

void addq(QUEUE *queue, element info)
{
	if (isFull(*queue)) {
		printf("queue is full, not added\n");
		return;
	}
	queue->rear++;
	queue->rear = queue->rear % MAX_QUEUE_SIZE;
	queue->item[queue->rear] = info;
}

element deleteq(QUEUE *queue)
{
	if (isEmpty(*queue)) {
		printf("queue is empty\n");
		exit(EXIT_FAILURE);
	}
	queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
	return queue->item[queue->front];
}
