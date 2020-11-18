#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

int N, K;
vector<int> feed;
vector<int> DP;

int solution(int idx) {
	if (idx >= N)
		return 0;
	if (DP[idx])
		return DP[idx];

	int a1 = 0, a2 = 0, energe = 0;
	int i = idx;
	for (; i < N && energe < K; i++)
		energe += feed[i];
	a1 = energe - K + solution(i);
	a2 = solution(idx + 1);
	
	DP[idx] = (a1 > a2) ? a1 : a2;
	return DP[idx];
}

int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &K);
	feed.resize(N);
	DP = vector<int>(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &feed[i]);
	printf("%d", solution(0));
	return 0;
}