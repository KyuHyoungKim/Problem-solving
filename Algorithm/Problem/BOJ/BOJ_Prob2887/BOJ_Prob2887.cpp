#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct tunnel {
	int head, tail, cost;
};
struct comp {
	bool operator()(const tunnel& a, const tunnel& b) {
		return a.cost < b.cost;
	}
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second < b.second;
	}
};

int find_root(vector<int>& root, int idx) {
	if (root[idx] == idx)
		return idx;
	else
		return root[idx] = find_root(root, root[idx]);
}
void unionize(vector<int>& root, int idx1, int idx2) {
	idx1 = find_root(root, idx1);
	idx2 = find_root(root, idx2);
	if (idx1 > idx2) swap(idx1, idx2);
	root[idx2] = root[idx1];
}

int main() {
	freopen("input.txt", "r", stdin);
	int N, res = 0;
	scanf("%d", &N);
	vector<vector<pair<int, int>>> planets(3, vector<pair<int, int>>(N));
	vector<tunnel> tunnels(3 * N - 3);
	vector<int> root(N);
	for (int i = 0; i < N; i++) {
		root[i] = i;
		for (int j = 0; j < 3; j++) {
			planets[j][i].first = i;
			scanf("%d", &planets[j][i].second);
		}
	}

	for (int i = 0; i < 3; i++)
		sort(planets[i].begin(), planets[i].end(), comp());

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < 3; j++) {
			tunnels[3 * i + j].head = planets[j][i].first;
			tunnels[3 * i + j].tail = planets[j][i + 1].first;
			tunnels[3 * i + j].cost = abs(planets[j][i].second - planets[j][i + 1].second);
		}
	}

	sort(tunnels.begin(), tunnels.end(), comp());
	for (int i = 0; i < tunnels.size(); i++) {
		if (find_root(root, tunnels[i].head) == find_root(root, tunnels[i].tail))
			continue;
		unionize(root, tunnels[i].head, tunnels[i].tail);
		res += tunnels[i].cost;
	}

	printf("%d", res);
	return 0;
}