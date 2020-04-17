#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>

using namespace std;

int ret = 0;
int solution(int num, int trial, int cnt)
{
	if (trial <= cnt)
	{
		if (num > ret)
			ret = num;
		return num;
	}
	
	string Num = to_string(num);
	string Num_temp = Num;

	char temp_char;
	for (int i = 0; i < Num.size(); i++)
	{
		for (int j = i + 1; j < Num.size(); j++)
		{
			Num = Num_temp;
			char temp = Num[i];
			Num[i] = Num[j];
			Num[j] = temp;
			num = stoi(Num);
			solution(num, trial, cnt+1);
		}
	}
	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ret = 0;
		int num = 0, trial = 0, temp = 0, cnt = 0;

		scanf("%d %d", &num, &trial);

		for (int i = num; i > 0; temp++)
			i /= 10;
		if (trial - temp + 1 > 0)
			cnt += (trial - temp + 1) / 2 * 2;
		printf("#%d %d\n", test_case, solution(num, trial, cnt));
	}
	return 0;
}