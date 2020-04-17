#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int solution(int number, int trial)
{
	string num = to_string(number);
	string temp = num;
	sort(temp.begin(), temp.end(),greater<char>());
	
	for (int count = 0, pos = 0; count < trial; count++)
	{
		for (int i = num.size() - 1; i >= pos; i--)
		{
			if (i == pos)
			{
				pos++;
				count--;
			}
			else if (num[i] == temp[pos])
			{
				num[i] = num[pos];
				num[pos] = temp[pos];
				pos++;
				break;
			}
		}
	}
	return stoi(num);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int num = 0, trial = 0;
		scanf("%d %d", &num, &trial);

		printf("#%d %d\n", test_case, solution(num, trial));
	}
	return 0;
}