#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, res = 1; 
		scanf("%d", &N);
		queue<pair<int, int>> q;
		pair<int, int> start, end;
		vector<pair<int, int>> beer(N);
		vector<int> check(N + 1, 0);
		scanf("%d %d", &start.first, &start.second);
		for (int i = 0; i < N; i++) scanf("%d %d", &beer[i].first, &beer[i].second);
		scanf("%d %d", &end.first, &end.second);
		q.push(start);
		beer.push_back(end);
		while (!q.empty() && res) {
			pair<int, int> now = q.front();
			q.pop();
			for (int i = 0; i < N + 1; i++) {
				int dist = abs(now.first - beer[i].first) + abs(now.second - beer[i].second);
				if (!check[i] && dist <= 1000) {
					q.push(beer[i]);
					check[i] = 1;
					if (beer[i] == end) {
						printf("happy\n");
						res = 0;
						break;
					}
				}
			}
		}
		if(res) printf("sad\n");
	}
	return 0;
}