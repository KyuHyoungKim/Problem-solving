#include <stdio.h>
#include <stdlib.h>

#define Num_of_Element 20

void BubbleSort(int arr[]);

int main(void)
{
	int Array[Num_of_Element] = { 0 };
	for (int i = 0; i < Num_of_Element; i++)
	{
		Array[i] = rand() % 50;
		printf("%d ", Array[i]);
	}
	printf("\n");
	BubbleSort(Array);
	for (int i = 0; i < Num_of_Element; i++)
		printf("%d ", Array[i]);

	return 0;
}

void BubbleSort(int arr[])
{
	int temp = 0;
	for (int i = 0; i < Num_of_Element - 1; i++)
		for (int j = 0; j < Num_of_Element - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
}