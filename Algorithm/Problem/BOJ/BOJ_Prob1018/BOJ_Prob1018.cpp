#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N = 0, M = 0;
	int ret = 64, temp = 0;
	char text[3] = { "WB" };
	freopen("input2.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	vector<vector<char>> board(N, vector<char>(M));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	for (int n = 0; n < 2; ++n)
	{
		for (int y = 0; y < N - 7; ++y)
			for (int x = 0; x < M - 7; ++x)
			{
				temp = 0;
				for (int i = y; i < y + 8; i++)
					for (int j = x; j < x + 8; j++)
					{
						if ((i + j) % 2 == 0 && board[i][j] == text[n]) continue;
						else if ((i + j) % 2 == 1 && board[i][j] != text[n]) continue;
						else ++temp;
					}
				if (temp < ret)
					ret = temp;
			}
	}
	printf("%d\n", ret);
	return 0;
}