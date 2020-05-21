#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(const pair<pair<int, string>, int>& a, pair<pair<int, string>, int>& b)
{
	if (a.first.first == b.first.first)
		return a.second < b.second;
	else
		return a.first.first < b.first.first;
}

int main(void)
{
	int N = 0;
	vector<pair<pair<int, string>,int>> User;
	string name; int age;
	pair<pair<int, string>,int> temp;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		cin >> age >> name;
		User.push_back(make_pair(make_pair(age, name), i));
	}

	sort(User.begin(), User.end(), comp);

	for (int i = 0; i < N; i++)
		cout << User[i].first.first << ' ' << User[i].first.second << '\n';

	return 0;
}