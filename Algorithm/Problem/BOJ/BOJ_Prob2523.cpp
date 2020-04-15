#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>

int main(void)
{
	int input_N = 0;
	int k = 1;

	scanf("%d", &input_N);

	for (int i = 1; i > 0; i += k)
	{
		for (int j = 0; j < i; j++)
			printf("*");
		printf("\n");
		if (i == input_N)
			k = -1;
	}
	return 0;
}