#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int NoSquareNumber(long long Min, long long Max);

int main(void)
{
	long long Min = 0, Max = 0;

	scanf("%lld %lld", &Min, &Max);
	printf("%d", NoSquareNumber(Min, Max));

	return 0;
}

int NoSquareNumber(long long Min, long long Max)
{
	int cnt = 0;

	int* Arr = NULL;
	Arr = (int*)malloc(sizeof(int) * (Max - Min + 1));
	memset(Arr, 0, sizeof(int) * (Max - Min + 1));

	for (long long i = 2; i <= sqrt(Max); i++)
	{
		for (long long j = Min / (i * i); i * i * j <= Max; j++)
		{
			if (i * i * j - Min >= 0)
				Arr[i * i * j - Min] = 1;
		}
	}
	for (int i = 0; i < (Max - Min + 1); i++)
		if (!Arr[i])
			cnt++;

	return cnt;
}