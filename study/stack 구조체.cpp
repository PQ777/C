#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100


typedef struct
{
	int stack[MAX_STACK_SIZE];
	int top;

}StackType;

void init_stack(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType *s)
{
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return (s->top > MAX_STACK_SIZE - 1);
}

void push(StackType* s, int value)
{
	if (is_full(s))
		printf("stack is full");
	else
	{
		s->top++;
		s->stack[s->top] = value;
		printf("%d\n", value);
	}
}

int pop(StackType* s)
{
	if (is_empty(s))
		printf("stack is empty");
	else
		return s->stack[s->top--];
		
}


int main()
{
	StackType* s = (StackType*)malloc(sizeof(StackType));
	init_stack(s);
	printf("stack push\n");
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);

	printf("\nstack pop\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%d\n", pop(s));
	}

	return 0;
}