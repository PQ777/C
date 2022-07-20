#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef int element;

typedef struct
{
	int front, rear;
	element Queue[MAX_QUEUE_SIZE];
}QueueType;

void init_queue(QueueType* q)
{
	q->front = 0;
	q->rear = 0;
}

int is_empty(QueueType* q)
{
	return q->front == q->rear;
}

int is_full(QueueType* q)
{
	return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}

void added_queue(QueueType* q, element value)
{
	if (is_full(q))
		printf("queue is full\n");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->Queue[q->rear] = value;
}

int delete_queue(QueueType* q)
{
	if (is_empty(q))
		printf("queue is empty\n");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->Queue[q->front];
}
element peek(QueueType* q)
{
	if (is_empty(q))
		printf("queue is empty\n");
	return(q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

int main()
{
	QueueType* q = (QueueType*)malloc(sizeof(QueueType));
	init_queue(q);

	added_queue(q, 1);
	added_queue(q, 3);
	added_queue(q, 5);

	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", delete_queue(q));
	}

	return 0;
}