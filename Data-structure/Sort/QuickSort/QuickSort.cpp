#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define Num_of_Element 5

void QuickSort(int* arr, int Left, int Right);

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
	QuickSort(Array, 0, Num_of_Element-1);
	for (int i = 0; i < Num_of_Element; i++)
		printf("%d ", Array[i]);
	return 0;
}

void QuickSort(int* arr, int Left, int Right)
{
	if (Left >= Right)
		return;
	int Pivot = arr[Right];
	int Left_temp = Left, Right_temp = Right;
	int temp = 0;
	for (; Left_temp < Right_temp;)
	{
		for (; arr[Left_temp] <= Pivot && Left_temp < Right_temp;)
			Left_temp++;
		for (; arr[Right_temp] >= Pivot && Left_temp < Right_temp;)
			Right_temp--;

		temp = arr[Left_temp];
		arr[Left_temp] = arr[Right_temp];
		arr[Right_temp] = temp;
	}
	temp = arr[Left_temp];
	arr[Left_temp] = arr[Right];
	arr[Right] = temp;
	QuickSort(arr, Left, Left_temp - 1);
	QuickSort(arr, Left_temp + 1, Right);
}