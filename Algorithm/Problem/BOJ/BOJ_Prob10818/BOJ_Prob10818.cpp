#include <iostream>

int main(void)
{
	int N = 0, Min = 1000000, Max = -1000000;
	int temp = 0;
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &temp);
		if (Min > temp)
			Min = temp;
		if (Max < temp)
			Max = temp;
	}
	printf("%d %d", Min, Max);
	return 0;
}