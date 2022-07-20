#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct
{
	int front;
	int rear;
	element Queue[MAX_QUEUE_SIZE];
}QueueType;

void init_queue(QueueType*q)
{
	q->rear = -1;
	q->front = -1;
}

int is_empty(QueueType* q)
{
	return q->front == q->rear;
}

int is_full(QueueType* q)
{
	return q->rear == MAX_QUEUE_SIZE - 1;
}

void added_queue(QueueType* q, element value)
{
	if (is_full(q))
		printf("queue is full\n");
	else
	{
		q->Queue[++(q->rear)] = value;
	}
}

int delete_queue(QueueType* q)
{
	if (is_empty(q))
		printf("queue is empty\n");
	else {
		int temp = q->Queue[++(q->front)];
		return temp;
	}
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