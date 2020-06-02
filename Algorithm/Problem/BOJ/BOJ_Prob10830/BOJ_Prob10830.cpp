#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>> dp[40];
int N;
vector<vector<int>> matrix_cross(vector<vector<int>>A, vector<vector<int>>B) {
	vector<vector<int>> ret(N, vector<int>(N));
	for(int i = 0 ; i<N; i++)
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				ret[i][j] += A[i][k] * B[k][j];
			}
			ret[i][j] %= 1000;
		}
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	long long B;
	scanf("%d %lld", &N, &B);
	vector<vector<int>> matrix(N, vector<int>(N));
	vector<vector<int>> res(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		res[i][i] = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &matrix[i][j]);
	dp[0] = matrix;
	int n = 1;
	for (long long bin = 1; bin < B; bin *= 2)
	{
		dp[n] = matrix_cross(dp[n - 1], dp[n - 1]);
		n++;
	}
	long long bin = 0;
	for (int i = 0;bin != B;i++)
	{
		if (B & ((long long)1 << i)) {
			bin |= (long long)1 << i;
			res = matrix_cross(res, dp[i]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}
	return 0;
}