#include <iostream>

int main(void)
{
	int N = 0, X = 0;
	int temp = 0;

	std::cin>>N>>X;

	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &temp);
		if (temp < X)
			std::cout << temp << " ";
	}

}