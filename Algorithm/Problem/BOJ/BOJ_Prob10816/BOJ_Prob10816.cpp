#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	freopen("input.txt", "r", stdin);
	int N = 0, M = 0;
	int* checked_p = (int*)malloc(sizeof(int) * 10000001);
	int* checked_m = (int*)malloc(sizeof(int) * 10000001);
	memset(checked_p, 0, sizeof(int) * 10000001);
	memset(checked_m, 0, sizeof(int) * 10000001);
	scanf("%d", &N);
	while(N--)
	{
		int temp = 0;
		scanf("%d", &temp);
		if (temp >= 0)
			checked_p[temp]++;
		else
			checked_m[-temp]++;
	}
	scanf("%d", &M);
	while (M--)
	{
		int temp = 0;
		scanf("%d", &temp);
		if (temp >= 0)
			printf("%d ", checked_p[temp]);
		else
			printf("%d ", checked_m[-temp]);
	}
	free(checked_p);
	free(checked_m);

	return 0;
}