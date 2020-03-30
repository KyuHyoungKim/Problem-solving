#include <iostream>
#include <vector>
#include <math.h>
void FindPrimeNum(int M, int N);

int main(void)
{
	int M = 0, N = 0;
	std::cin >> M >> N;
	FindPrimeNum(M, N);
	return 0;
}

void FindPrimeNum(int M, int N)
{
	std::vector<int> Num(N+1, 0);
	Num[1] = 1;
	for (int i = 2; i < sqrt(N); i++)
	{
		for (int j = 2; i * j <= N; j++)
		{
			Num[i * j] = 1;
		}
	}
	for (int i = M; i <= N; i++)
		if (Num[i] == 0)
			printf("%d\n", i);
}