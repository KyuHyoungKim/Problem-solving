#include <iostream>
#include <vector>
#include <algorithm>

const int Num_of_Element = 20;

template <typename T>
void Print(T Arr)
{
	for (int i = 0; i < Num_of_Element; i++)
		std::cout << Arr[i] << "\n";
}

int main(void)
{
	// Vector
	printf("sort function with vector (less) : \n");
	std::vector<int> A;					
	for (int i = 0; i < Num_of_Element; i++)
		A.push_back(rand() % 100);
	
	std::sort(A.begin(), A.end(), std::less<int>());
	Print(A);
	printf("sort function with vector(greater) : \n");

	std::sort(A.begin(), A.end(), std::greater<int>());
	Print(A);

	// Array
	printf("sort function with array : \n");
	int Array[Num_of_Element] = { 0 };
	for (int i = 0; i < 20; i++)
		Array[i] = rand() % 100;

	std::sort(Array, Array + Num_of_Element);
	Print(Array);
	return 0;
}
