#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int input = 0;
	int result = 0;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &input);
		result += (input * input);
	}

	result %= 10;

	printf("%d\n", result);

	return 0;
}