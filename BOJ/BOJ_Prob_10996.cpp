#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int Input_N = 0, cnt = 0;

	scanf("%d", &Input_N);
	if (Input_N <= 1)
		printf("*");
	else
	{
		for (int j = 0; j < Input_N; j++)
		{
			cnt = 0;
			for (int i = 0; i < Input_N; i++)
			{
				if (cnt % 2 == 0)
					printf("*");
				else
					printf(" ");
				cnt++;
			}
			printf("\n");
			cnt = 0;
			for (int i = 0; i < Input_N; i++)
			{
				if (cnt % 2 == 1)
					printf("*");
				else
					printf(" ");
				cnt++;
			}
			printf("\n");
		}
	}
	return 0;
}