#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N;
	double res = 0;
	pair<int, int> start;
	scanf("%d", &N);
	scanf("%d %d", &start.first, &start.second);
	vector<pair<int, int>> vec(N - 1);
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec[i].first = x - start.first;
		vec[i].second = y - start.second;
	}
	for (int i = 0; i < N - 2; i++)
		res += (long long)vec[i].first * vec[i + 1].second - (long long)vec[i].second * vec[i + 1].first;
	res /= 2;
	
	printf("%.1lf", fabs(res));

	return 0;
}