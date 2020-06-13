#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>> res;
int N, M;

void sol(int now, int cnt, vector<int> ret) {
	if (cnt == M) {
		res.push_back(ret);
		return;
	}
	if (now == N) return;
	ret.push_back(now + 1);
	sol(now, cnt + 1, ret);
	ret.pop_back();
	sol(now + 1, cnt, ret);
}

int main() {
	scanf("%d %d", &N, &M);
	sol(0, 0, {});
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[i].size(); j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}
	return 0;
}