#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
vector<pair<int, int>> res;
void hanoi(int n, int start, int mid, int end) {
	if (n == 1)
		res.push_back(make_pair(start, end));
	else {
		hanoi(n - 1, start, end, mid);
		res.push_back(make_pair(start, end));
		hanoi(n - 1, mid, start, end);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	hanoi(N, 1, 2, 3);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}