#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

bool check[10];
int valid_check(int num);

int main()
{
	//freopen("input.txt", "r", stdin);
	memset(check, true, sizeof(check));
	int N = 0, M = 0, button = 0, res = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &button);
		check[button] = false;
	}

	res = abs(N - 100);

	for (int i = N; i >= 0; --i)
	{
		int ret = valid_check(i);
		if (ret > 0)
		{
			ret += N - i;
			if (ret < res)
				res = ret;
			break;
		}
	}
	for (int i = N; i <= 900000; ++i)
	{
		int ret = valid_check(i);
		if (ret > 0)
		{
			ret += i - N;
			if (ret < res)
				res = ret;
			break;
		}
	}

	printf("%d\n", res);
	return 0;
}

int valid_check(int num)
{
	int ret = 0;
	while (1) {
		if (check[num % 10])
			ret++;
		else
		{
			ret = -1;
			break;
		}
		num /= 10;
		if (num == 0)
			break;
	}
	return ret;
}