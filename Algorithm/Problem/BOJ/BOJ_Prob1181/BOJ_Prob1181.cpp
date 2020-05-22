#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const string& a, const string& b)
{
	if (a.size() != b.size())
		return a.size() < b.size();
	else
		return a < b;
}
int main(void)
{
	freopen("input.txt", "r", stdin);
	int N = 0;
	vector<string> words;
	scanf("%d", &N);
	getchar();
	while (N--) {
		string input;
		cin >> input;
		words.push_back(input);
	}
	sort(words.begin(), words.end(),comp);
	cout << words[0] << '\n';

	for (int i = 1; i < words.size(); i++)
	{
		if (words[i].compare(words[i - 1]))
			cout << words[i] << '\n';
	}
	return 0;
}