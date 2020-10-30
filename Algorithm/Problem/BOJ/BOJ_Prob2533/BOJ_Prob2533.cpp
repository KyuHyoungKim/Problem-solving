#define _CRT_SECURE_NO_WARNINGS
#define INF 1234567891
#include <cstdio>
#include <vector>

using namespace std;
vector<vector<int>> tree;
vector<vector<int>> DP;

int solution(int prev, int here, bool isvisit) {
	if (DP[here][isvisit]>=0)
		return DP[here][isvisit];

	int ret = 0;
	if (isvisit)
		ret++;

	for (int i = 0; i < tree[here].size(); i++) {
		int next_node = tree[here][i];
		int a1 = INF, a2 = INF;
		if (next_node == prev)
			continue;

		if (isvisit) {
			a1 = solution(here, next_node, true);
			a2 = solution(here, next_node, false);
		}
		else 
			a1 = solution(here, next_node, true);
		
		ret += (a1 < a2) ? a1 : a2;
	}
	DP[here][isvisit] = ret;
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);

	int N, a1, a2, res;
	scanf("%d", &N);
	tree.resize(N);
	DP.resize(N, vector<int>(2, -1));
	for (int i = 1; i < N; i++) {
		int node1, node2;
		scanf("%d %d", &node1, &node2);
		node1--; node2--;
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}
	a1 = solution(-1, 0, true);
	a2 = solution(-1, 0, false);
	res = (a1 < a2) ? a1 : a2;
	
	printf("%d", res);
	return 0;
}