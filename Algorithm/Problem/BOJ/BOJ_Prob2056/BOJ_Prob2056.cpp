#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int N, res = 0;
vector<vector<int>> graph;
vector<int> time;
vector<int> DP;
int meastime(int num) {
	if (DP[num]) return DP[num];
	int a, ret = 0;
	for (int i = 0; i < graph[num].size(); i++) {
		a = meastime(graph[num][i]);
		if (a > ret) ret = a;
	}
	ret += time[num];
	DP[num] = ret;
	if (ret > res) res = ret;
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	graph.resize(N); time.resize(N); DP.resize(N);
	for (int i = 0; i < N; i++) {
		int K, node;
		scanf("%d %d", &time[i], &K);
		for (int j = 0; j < K; j++) {
			scanf("%d", &node);
			graph[i].push_back(node - 1);
		}
	}
	for (int i = 0; i < N; i++) 
		meastime(i);

	printf("%d\n", res);
	return 0;
}