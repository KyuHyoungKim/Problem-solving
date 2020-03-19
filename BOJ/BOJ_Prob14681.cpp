#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x = 0, y = 0;
	int result = 0;
	scanf("%d %d", &x, &y);

	if (x > 0)
	{
		if (y > 0)
			result = 1;
		else
			result = 4;
	}
	else
	{
		if (y > 0)
			result = 2;
		else
			result = 3;
	}

	printf("%d\n", result);

	return 0;
}