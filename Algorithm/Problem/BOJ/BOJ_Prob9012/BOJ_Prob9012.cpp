#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int N = 0;
	string result;
	string str;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		result = "YES";
		str.clear();
		stack<char> Stack;
		cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(')
				Stack.push(str[i]);
			else if (str[i] == ')')
			{
				if (Stack.empty())
				{
					result = "NO";
					break;
				}
				Stack.pop();
			}
		}
		if (!Stack.empty())
			result = "NO";
		cout << result << endl;
	}
	return 0;
}