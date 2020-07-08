#define _CRT_SECURE_NO_WARNINGS
#define INF 2000000000
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int N, min_sum = INF;
	scanf("%d", &N);
	vector<int> solutions(N);
	pair<int, int> res;
	for (int i = 0; i < N; i++)
		scanf("%d", &solutions[i]);
	
	for (int i = 0, j = N - 1; i < j;) {
		int temp = solutions[i] + solutions[j];
		if (abs(temp) < min_sum) {
			res.first = solutions[i];
			res.second = solutions[j];
			min_sum = abs(temp);
		}
		if (temp < 0) i++;
		else if (temp > 0) j--;
		else break;
	}

	printf("%d %d", res.first, res.second);
	return 0;
}