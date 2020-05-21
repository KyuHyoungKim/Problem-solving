#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N = 0;
	scanf("%d", &N);
	int i;
	for (i = 1; i < N; i++)
	{
		int num = i;
		int temp = num;
		do {
			num += temp % 10;
			temp /= 10;
		} while (temp > 0);
		if (num == N)
		{
			printf("%d\n", i);
			break;
		}
	}
	if (i == N)
		printf("0\n");
	return 0;
}