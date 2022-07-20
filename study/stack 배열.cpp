#include <stdio.h>
#define MAX_STACK_SIZE 100 // ���� �ִ������ 100

int stack[MAX_STACK_SIZE]; //100�� ũ�⸦ ���� ���� �迭 ����
int top = -1; // top����: �ֻ���� �������� ��ġ ����Ŵ(-1�� �ʱ�ȭ)

int IsEmpty() // ���� ����ִ��� Ȯ��
{
	if (top < 0) // top�� 0���� ������ 1��ȯ
		return 1;
	else
		return 0;
}

int IsFull() // ������ �����ִ��� Ȯ��
{
	if (top > MAX_STACK_SIZE - 1) // top�� ���� �ִ������ -1 ���� ũ�� ��ȯ 1
		return 1;
	else
		return 0;
}

void push(int value) // ���ÿ� �� �ֱ�
{
	if (IsFull() == 1) // IsFull �Լ� ��ȯ���� 1�̸� ����
		printf("stack is full");
	else
		stack[++top] = value; // value���� 1 ������ ���� �迭�� �ֱ�
}
int pop() // ���ÿ� �� ����
{
	if (IsEmpty() == 1)
		printf("stack is empty");
	else
		return stack[top--]; // �ش� ���� �迭���� 1 ����
}


int main()
{
	push(3);
	push(5);
	push(12);

	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());

	return 0;
}