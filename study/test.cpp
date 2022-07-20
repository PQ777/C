#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef int element;

typedef struct
{
	element queue[MAX_QUEUE_SIZE];
	int front, rear;

}QueueType;

void init_queue(QueueType* q)
{
	q->front = 0;
	q->rear = 0;
}

int is_empty(QueueType* q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

int is_full(QueueType* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

void added_queue(QueueType* q, element val)
{
	if (is_full(q))
		perror("queue is full\n");
	else
		q->queue[++(q->rear)] = val;
}

int delete_queue(QueueType* q)
{
	if (is_empty(q))
		perror("queue is empty\n");
	else
		return q->queue[(q->rear)--];
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