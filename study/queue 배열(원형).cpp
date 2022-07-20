#include <stdio.h>
#define MAX 100 //�ִ� ũ�� ����
int front = -1; // ��µ� ��ġ�� �˸��� �� -1 �ʱ�ȭ
int rear = -1;  // �Է°��� ��ġ�� �˸��� �� -1 �ʱ�ȭ
int queue[MAX];

int is_empty()
{
	if (front == rear) // front�� rear�� ������ ť�� ����ִ»���
		return 1;
	else
		return 0;
}
int is_full()
{
	int temp = (rear + 1) % MAX; // ����ť���� rear+1�� MAX�� ���� ��������

	if (temp == front) //front�� ������ ť�� ������ �ִ� ����
		return 1;
	else
		return 0;
}

void add_queue(int value)
{
	if (is_full())
		printf("queue is full\n");
	else
	{
		rear = (rear + 1) % MAX; // rear �������� ��(++rear )
		queue[rear] = value; // ++rear��° �׿� ���� �־��ش�
	}
}

int delet_queue()
{
	if (is_empty())
		printf("queue is empty\n");
	else
	{
		front = (front + 1) % MAX; // front ������° ��(++front)
		return queue[front]; // ++front��° �׿��� ���� ���´�
	}
}

int main()
{
	add_queue(4);
	add_queue(7);
	add_queue(12);

	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", delet_queue());
	}
	delet_queue();
	return 0;
}