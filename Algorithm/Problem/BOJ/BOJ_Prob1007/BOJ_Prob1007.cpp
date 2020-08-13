#define _CRT_SECURE_NO_WARNINGS
#define INF 1234567891
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int N;
vector<pair<int, int>> points;

double sol(int idx, int cnt, pair<int, int> sum) {
	double a1, a2;
	if (cnt > N / 2)
		return INF;
	if (idx >= N) {
		if (cnt < N / 2)
			return INF;
		else
			return sqrt(pow(sum.first, 2) + pow(sum.second, 2));
	}
	sum.first += points[idx].first;
	sum.second += points[idx].second;
	a1 = sol(idx + 1, cnt + 1, sum);

	sum.first -= 2 * points[idx].first;
	sum.second -= 2 * points[idx].second;
	a2 = sol(idx + 1, cnt, sum);

	return a1 < a2 ? a1 : a2;
}
int main() {
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		double res;
		scanf("%d", &N);
		vector<pair<int, int>> points_init(N);
		points.swap(points_init);
		for (int i = 0; i < N; i++)
			scanf("%d %d", &points[i].first, &points[i].second);
		res = sol(0, 0, { 0,0 });
		printf("%lf\n", res);
	}
	return 0;
}