#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int N = 0, M = 0;
	scanf("%d %d", &N, &M);
	vector<int> buttons(M);
	for (int i = 0; i < M; i++)
		scanf("%d", &buttons[i]);
	int ret = 1234567891;
	int temp_ret, temp_num;

	if (M == 0)
	{
		temp_num = N;
		ret = 0;
		if (N == 0)
			ret++;
		for (; temp_num > 0;)
		{
			ret++;
			temp_num /= 10;
		}
	}
	else
	{
		for (int i = 0; i < 1000000; i++)
		{
			string num = to_string(i);
			for (int j = 0; j < M; j++)
			{
				if ((int)num.find(to_string(buttons[j])) >= 0)
					break;
				else if (j == M - 1)
				{
					temp_num = i, temp_ret = N - i;
					if (temp_ret < 0)
						temp_ret *= -1;
					if (temp_num == 0)
						temp_ret++;
					for (; temp_num > 0;)
					{
						temp_ret++;
						temp_num /= 10;
					}
					if (temp_ret < ret)
						ret = temp_ret;
				}
			}
		}
	}
	if (N < 100)
		temp_ret = 100 - N;
	else
		temp_ret = N - 100;

	if (temp_ret < ret)
		ret = temp_ret;

	printf("%d\n", ret);
	return 0;
}