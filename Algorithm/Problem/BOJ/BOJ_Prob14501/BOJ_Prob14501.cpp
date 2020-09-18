#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int N;
vector<pair<int, int>> consult;

int sol(int idx, int cost) {
	if (idx >= N)
		return cost;
	int ret, a1 = 0, a2 = 0;

	a1 = sol(idx + 1, cost);
	if (idx + consult[idx].first <= N)
		a2 = sol(idx + consult[idx].first, cost + consult[idx].second);
	ret = (a1 > a2) ? a1 : a2;
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	int res = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		pair<int, int> temp;
		scanf("%d %d", &temp.first, &temp.second);
		consult.push_back(temp);
	}
	res = sol(0, 0);
	printf("%d", res);
	return 0;
}