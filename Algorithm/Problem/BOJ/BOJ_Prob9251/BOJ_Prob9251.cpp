#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	char str1[1001], str2[1001];
	scanf("%s %s", str1, str2);
	int N = strlen(str1), M = strlen(str2);
	vector<vector<int>> LCS(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (str1[i - 1] == str2[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else LCS[i][j] = (LCS[i - 1][j] > LCS[i][j - 1]) ? LCS[i - 1][j] : LCS[i][j - 1];

	printf("%d\n", LCS[N][M]);

	return 0;
}