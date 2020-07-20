#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int T, N, M;
	long long res = 0;

	scanf("%d %d", &T, &N);
	vector<int> A(N);
	vector<int> A_sums(N * (N + 1) / 2);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	
	scanf("%d", &M);
	vector<int> B(M);
	vector<int> B_sums(M * (M + 1) / 2);
	for (int i = 0; i < M; i++)
		scanf("%d", &B[i]);
	
	for (int i = 0, cnt = 0; i < N; i++) {
		int a_sum = 0;
		for (int j = i; j < N; j++) {
			a_sum += A[j];
			A_sums[cnt] = a_sum;
			cnt++;
		}
	}
	for (int i = 0, cnt = 0; i < M; i++) {
		int b_sum = 0;
		for (int j = i; j < M; j++) {
			b_sum += B[j];
			B_sums[cnt] = b_sum;
			cnt++;
		}
	}
	
	sort(B_sums.begin(), B_sums.end());

	for (int i = 0; i < A_sums.size(); i++) {
		int num = T - A_sums[i];
		int upper = upper_bound(B_sums.begin(), B_sums.end(), num) - B_sums.begin();
		int lower = lower_bound(B_sums.begin(), B_sums.end(), num) - B_sums.begin();
		res += (upper - lower);
	}
	printf("%d", res);
	return 0;
}