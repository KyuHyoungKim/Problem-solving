#include <stdio.h>
#include <stdlib.h>

#define Num_of_Element 20

void SelectionSort(int* Arr);

int main(void)
{
	int Array[Num_of_Element] = { 0 };

	for (int i = 0; i < Num_of_Element; i++)
	{
		Array[i] = rand() % 50;
		printf("%d ", Array[i]);
	}
	printf("\n");
	SelectionSort(Array);
	for (int i = 0; i < Num_of_Element; i++)
		printf("%d ", Array[i]);
		
	return 0;
}

void SelectionSort(int* Arr)
{
	int min = 0, pos = 0;;
	for (int i = 0; i < Num_of_Element; i++)
	{
		min = Arr[i];
		pos = i;
		for (int j = i; j < Num_of_Element; j++)
		{
			if (min > Arr[j])
			{
				min = Arr[j];
				pos = j;
			}
		}
		Arr[pos] = Arr[i];
		Arr[i] = min;
	}
}