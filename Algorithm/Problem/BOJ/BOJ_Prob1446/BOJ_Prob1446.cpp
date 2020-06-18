#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int N, D;
vector<vector<int>> path; // start, end, length
int sol(int pos, int len) {
	int ret = D - pos + len;
	int a = 1234567891;
	for (int i = 0; i < N; i++) {
		if (path[i][0] >= pos)
			a = sol(path[i][1], path[i][0] - pos + path[i][2] + len);
		if (a < ret) ret = a;
	}
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	int res = 0;
	scanf("%d %d", &N, &D);
	
	while (N--) {
		vector<int> input(3);
		scanf("%d %d %d", &input[0], &input[1], &input[2]);
		if (input[1] > D) continue;
		path.push_back(input);
	}
	N = path.size();
	res = sol(0, 0);
	printf("%d\n", res);
	return 0;
}