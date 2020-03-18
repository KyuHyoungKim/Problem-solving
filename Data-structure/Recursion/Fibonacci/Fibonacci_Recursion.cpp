#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Fibonacci(int N);

int main(void)
{
	int result = 0, N = 0;
	scanf("%d", &N);
	result = Fibonacci(N);
	printf("%d", result);

	return 0;
}

int Fibonacci(int N)
{
	if (N <= 0)
		return 0;
	if (N <= 2)
		return 1;
	else
		return Fibonacci(N - 2) + Fibonacci(N - 1);
}