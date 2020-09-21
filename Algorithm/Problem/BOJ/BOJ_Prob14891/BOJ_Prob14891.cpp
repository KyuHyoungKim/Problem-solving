#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int N, res = 0;
	string gears[5];
	vector<pair<int, int>> contact(5);
	for (int i = 1; i <= 4; i++) {
		cin >> gears[i];
		contact[i].first = 6;
		contact[i].second = 2;
	}
	cin >> N;
	vector<pair<int, int>> rotations(N);
	for (int i = 0; i < N; i++)
		cin >> rotations[i].first >> rotations[i].second;

	for (int i = 0; i < N; i++) {
		int dir = rotations[i].second;
		vector<pair<bool, int>> check(5, make_pair(false, 0));
		check[rotations[i].first].first = true;
		check[rotations[i].first].second = dir;
			
		for (int j = rotations[i].first + 1; j <= 4; j++) {
			if (gears[j - 1][contact[j - 1].second] == gears[j][contact[j].first])
				break;
			dir *= -1;
			check[j].first = true;
			check[j].second = dir;
		}

		dir = rotations[i].second;
		for (int j = rotations[i].first - 1; j > 0; j--) {
			if (gears[j][contact[j].second] == gears[j + 1][contact[j + 1].first])
				break;
			dir *= -1;
			check[j].first = true;
			check[j].second = dir;
		}

		for (int i = 1; i <= 4; i++) {
			if (!check[i].first)
				continue;

			contact[i].first -= check[i].second;
			if (contact[i].first < 0)
				contact[i].first += 8;
			else if (contact[i].first >= 8)
				contact[i].first -= 8;

			contact[i].second -= check[i].second;
			if (contact[i].second < 0)
				contact[i].second += 8;
			else if (contact[i].second >= 8)
				contact[i].second -= 8;
		}
	}
	for (int i = 1; i <= 4; i++) {
		char polarity = gears[i][(contact[i].first + 2) % 8];
		if (polarity == '1')
			res += (1 << (i - 1));
	}
	printf("%d", res);
	return 0;
}