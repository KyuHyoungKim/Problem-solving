#include <iostream>

int main(void)
{
	int N = 0;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}