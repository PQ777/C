#include <stdio.h>
#define MAX 100 //최대 크기 설정
int front = -1; // 출력될 위치를 알리는 값 -1 초기화
int rear = -1;  // 입력값의 위치를 알리는 값 -1 초기화
int queue[MAX];

int is_empty()
{
	if (front == rear) // front와 rear가 같으면 큐는 비어있는상태
		return 1;
	else
		return 0;
}
int is_full()
{
	int temp = (rear + 1) % MAX; // 원형큐에서 rear+1을 MAX로 나눈 나머지값

	if (temp == front) //front와 같으면 큐는 가득차 있는 상태
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
		rear = (rear + 1) % MAX; // rear 다음번쨰 항(++rear )
		queue[rear] = value; // ++rear번째 항에 값을 넣어준다
	}
}

int delet_queue()
{
	if (is_empty())
		printf("queue is empty\n");
	else
	{
		front = (front + 1) % MAX; // front 다음번째 항(++front)
		return queue[front]; // ++front번째 항에서 값을 빼온다
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