#include <stdio.h>

void printArr(int value[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%2d", value[i]);
	printf("\n");
}

void selection_sort(int* value, int n)
{
	int min, temp = 0;

	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (value[min] > value[j])
				min = j;
		}
		temp = value[i];
		value[i] = value[min];
		value[min] = temp;
	}
}

int main()
{
	int value[] = { 4, 7, 9, 11, 3, 7, 6 };
	int n = sizeof(value) / sizeof(int);

	printArr(value, n);
	selection_sort(value, n);
	printArr(value, n);

	return 0;
}

