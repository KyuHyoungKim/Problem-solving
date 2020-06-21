#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	string str1, str2, res = "";
	getline(cin, str1);
	getline(cin, str2);
	int N = str1.size(), M = str2.size();
	vector<vector<int>> LCS(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (str1[i - 1] == str2[j - 1])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else
				LCS[i][j] = (LCS[i - 1][j] > LCS[i][j - 1]) ? LCS[i - 1][j] : LCS[i][j - 1];

	for (int i = N, j = M, cnt = LCS[i][j]; cnt > 0;)
		if (LCS[i][j] == LCS[i][j - 1])
			--j;
		else if (LCS[i][j] == LCS[i - 1][j])
			--i;
		else {
			res = str2[j - 1] + res;
			--i; --j; --cnt;
		}

	cout << LCS[N][M] << '\n' << res;
	return 0;
}