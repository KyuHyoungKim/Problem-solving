#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
vector<int> series;
vector<int> length;
int N;
int res;
int sol(int now) {
	if (length[now]) return length[now];
	if (now == N) return 1;
	int ret = 0, a = 0;
	for (int i = now + 1; i < series.size(); i++) {
		if (series[i] > series[now]) {
			a = sol(i);
			if (ret < a) ret = a;
		}
	}
	ret++;
	length[now] = ret;
	if (ret > res) res = ret;
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	series.resize(N);
	length.resize(N);
	res = 0;
	for (int i = 0; i < N; i++)
		scanf("%d", &series[i]);
	for (int i = 0; i < N; i++)
		sol(i);
	printf("%d\n", res);
	return 0;
}