#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Factorial(int n);

int main(void)
{
	int result = 0, N = 0;
	scanf("%d", &N);
	result = Factorial(N);
	printf("%d\n", result);

	return 0;
}

int Factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n* Factorial(n - 1);
}