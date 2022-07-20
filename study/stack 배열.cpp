#include <stdio.h>
#define MAX_STACK_SIZE 100 // 스택 최대사이즈 100

int stack[MAX_STACK_SIZE]; //100의 크기를 갖는 스택 배열 생성
int top = -1; // top변수: 최상단의 데이터의 위치 가리킴(-1로 초기화)

int IsEmpty() // 스택 비어있는지 확인
{
	if (top < 0) // top이 0보다 작으면 1반환
		return 1;
	else
		return 0;
}

int IsFull() // 스택이 꽉차있는지 확인
{
	if (top > MAX_STACK_SIZE - 1) // top이 스택 최대사이즈 -1 보다 크면 반환 1
		return 1;
	else
		return 0;
}

void push(int value) // 스택에 값 넣기
{
	if (IsFull() == 1) // IsFull 함수 반환값이 1이면 실행
		printf("stack is full");
	else
		stack[++top] = value; // value값을 1 증가한 스택 배열에 넣기
}
int pop() // 스택에 값 빼기
{
	if (IsEmpty() == 1)
		printf("stack is empty");
	else
		return stack[top--]; // 해당 스택 배열에서 1 감소
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