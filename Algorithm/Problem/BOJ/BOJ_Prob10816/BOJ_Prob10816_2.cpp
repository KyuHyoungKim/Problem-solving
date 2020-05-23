#include <stdio.h>
int checked[20000001] = { 0 };
int main(void)
{
	int N = 0, M = 0, temp = 0;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &temp);
		checked[10000000 + temp]++;
	}
	scanf("%d", &M);
	while (M--)
	{
		scanf("%d", &temp);
		printf("%d ", checked[10000000 + temp]);
	}
	return 0;
}