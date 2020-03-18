#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int result = 0, N = 0;
	int temp[21] = { 0, 1, 1 };
	scanf("%d", &N);
	for (int i = 3; i <= N; i++)
		temp[i] = temp[i - 2] + temp[i - 1];

	result = temp[N];

	printf("%d\n", result);
	return 0;
}