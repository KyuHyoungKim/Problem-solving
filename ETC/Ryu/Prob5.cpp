#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

int N, K;
vector<int> feed;
vector<ll> DP;
vector<pair<int, int>> energe_n_nextpos;

ll solution(int idx) {
	if (idx >= N)
		return 0;
	if (DP[idx]>= 0)
		return DP[idx];
	
	ll a1 = 0, a2 = 0;
	a1 = energe_n_nextpos[idx].first + solution(energe_n_nextpos[idx].second);
	a2 = solution(idx + 1);

	DP[idx] = (a1 > a2) ? a1 : a2;
	return DP[idx];
}

void simulate_energe_n_nextpos() {
	int energe = 0;
	int st = 0;
	for (int i = 0; i < N; i++) {
		energe += feed[i];
		while (energe >= K) {
			energe_n_nextpos[st].first = energe - K;
			energe_n_nextpos[st].second = i + 1;
			energe -= feed[st];
			st++;
		}
	}

	while (st < N) {
		energe_n_nextpos[st].first = 0;
		energe_n_nextpos[st].second = N;
		st++;
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &K);
	feed.resize(N);
	DP.resize(N, -1);
	energe_n_nextpos.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &feed[i]);
	simulate_energe_n_nextpos();

	printf("%lld", solution(0));
	return 0;
}