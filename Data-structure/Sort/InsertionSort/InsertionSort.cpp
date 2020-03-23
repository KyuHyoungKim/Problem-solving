#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define Num_of_Element 20

void InsertionSort(int* arr);

int main(void)
{
	int Array[Num_of_Element] = { 0 };
	srand(time(NULL));
	for (int i = 0; i < Num_of_Element; i++)
	{
		Array[i] = rand() % 50;
		printf("%d ", Array[i]);
	}
	printf("\n");
	InsertionSort(Array);
	for (int i = 0; i < Num_of_Element; i++)
		printf("%d ", Array[i]);
	return 0;
}

void InsertionSort(int* arr)
{
	int temp = 0;
	int j = 0;
	for (int i = 1; i < Num_of_Element; i++)
	{
		for (j = i-1; arr[j] > arr[i]; j--);
		temp = arr[i];
		for (int k = i; k > j+1; k--)
			arr[k] = arr[k - 1];
		arr[j+1] = temp;
	}
}