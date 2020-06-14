#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int T, start, end;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &start, &end);
		queue<pair<int, string>> q;
		vector<int> check(10000);
		string res;
		q.push(make_pair(start, ""));
		check[start]++;
		while (!q.empty()) {
			int now = q.front().first;
			string order = q.front().second;
			q.pop();
			int temp;

			temp = now * 2 % 10000;
			if (temp == end) {
				res = order + "D";
				break;
			}
			else if(!check[temp]){
				q.push(make_pair(temp, order + "D"));
				check[temp]++;
			}

			temp = now - 1;
			if (temp < 0) temp = 10000 + temp;
			if (temp == end) {
				res = order + "S";
				break;
			}
			else if (!check[temp]) {
				q.push(make_pair(temp, order + "S"));
				check[temp]++;
			}

			temp = now * 10;
			if (temp >= 10000) temp = (temp + temp / 10000) % 10000;
			if (temp == end) {
				res = order + "L";
				break;
			}
			else if (!check[temp]) {
				q.push(make_pair(temp, order + "L"));
				check[temp]++;
			}

			temp = (now + (now % 10 * 10000)) / 10;
			if (temp == end) {
				res = order + "R";
				break;
			}
			else if (!check[temp]) {
				q.push(make_pair(temp, order + "R"));
				check[temp]++;
			}
		}

		cout << res << '\n';
	}
	return 0;
}