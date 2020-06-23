#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	string res, str, bomb;
	cin >> str >> bomb;
	int len_bomb = bomb.size();
	for (int i = 0; str[i] != '\0'; i++)
	{
		res += str[i];
		if (str[i] == bomb[len_bomb - 1] && len_bomb <= res.size())
		{
			string q = "";
			for (int j = 1; j <= len_bomb; j++)
			{
				char temp = res.back();
				if (temp == bomb[len_bomb - j])
				{
					q = temp + q;
					res.pop_back();
				}
				else
				{
					res += q;
					break;
				}
			}
		}
	}

	if (res.empty()) res = "FRULA";
	cout << res;
	return 0;
}