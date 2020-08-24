#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> stats;
vector<int> A, B;
int N, team_A = 0, team_B = 0, res = 1234567891;
void init();
void sol(int idx, int A_cnt, int A_sum, int B_sum);
int stat_calc(int sum, int team);

int main() {
	freopen("input.txt", "r", stdin);
	init();
	sol(0, 0, 0, 0);
	printf("%d", res);
	return 0;
}

void init() {
	scanf("%d", &N);
	vector<vector<int>> stats__(N, vector<int>(N));
	stats.swap(stats__);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &stats[i][j]);
}

void sol(int idx, int A_cnt, int A_sum, int B_sum) {
	if (A_cnt == N / 2) {
		vector<int> B__ = B;
		int ret = 1234567891;

		for (int i = idx; i < N; i++) {
			B.push_back(i);
			B_sum = stat_calc(B_sum, 1);
		}
		B.swap(B__);
		ret = abs(A_sum - B_sum);
		if (ret < res) res = ret;
		return;
	}
	else if (A_cnt < idx - N / 2) {
		return;
	}
	A.push_back(idx);
	sol(idx + 1, A_cnt + 1, stat_calc(A_sum,0), B_sum);
	A.pop_back();

	B.push_back(idx);
	sol(idx + 1, A_cnt, A_sum, stat_calc(B_sum, 1));
	B.pop_back();
}

int stat_calc(int sum, int team) {
	vector<int>* members;

	if (team)
		members = &B;
	else
		members = &A;
	
	int new_member = members->back();
	for (int i = 0; i < members->size() - 1; i++) {
		sum += stats[new_member][members->at(i)];
		sum += stats[members->at(i)][new_member];
	}

	return sum;
}