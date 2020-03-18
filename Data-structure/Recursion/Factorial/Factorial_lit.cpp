#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int result = 1, N = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		result *= i;
	printf("%d\n", result);

	return 0;
}