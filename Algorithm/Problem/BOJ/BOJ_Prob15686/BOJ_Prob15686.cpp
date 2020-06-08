#define _CRT_SECURE_NO_WARNINGS
#define INF 1234567891
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;
int N, M, res = INF;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
void chick_dist(int now, int cnt, vector<int> chick) {
	int ret = 0;
	if (cnt == M) {
		vector<int> dist(home.size(), INF);
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < home.size(); j++) {
				int X = abs(chicken[chick[i]].second - home[j].second);
				int Y = abs(chicken[chick[i]].first - home[j].first);
				if (dist[j] > X + Y) dist[j] = X + Y;
			}
		}
		for (int i = 0; i < dist.size(); i++) ret += dist[i];
		if (ret < res) res = ret;
	}
	else if (now != chicken.size()) {
		chick_dist(now + 1, cnt, chick);
		chick.push_back(now);
		chick_dist(now + 1, cnt + 1, chick);
	}
	return;
}
int main() {
	freopen("input.txt", "r", stdin);
	int input;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &input);
			if (input == 0) continue;
			else if (input == 1) home.push_back(make_pair(i, j));
			else if (input == 2) chicken.push_back(make_pair(i, j));
		}
	chick_dist(0, 0, {});
	printf("%d\n", res);
	return 0;
}