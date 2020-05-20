#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N = 0, K = 0, res = 1;
	scanf("%d %d", &N, &K);

	for (int i = N; i > K; --i)
		res *= i;
	for (int i = N - K; i > 1; --i)
		res /= i;

	printf("%d\n", res);
	return 0;
}