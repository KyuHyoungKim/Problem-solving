#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int res = 0;
int N;
void NQueen(vector<int>board, int cnt) {
	if (cnt == N) {
		res++;
		return;
	}
	for (int i = 0; i < N; i++) {
		int check = 1;

		for (int j = 1; j <= cnt; j++)
			if (board[cnt - j] == i || board[cnt - j] == i - j || (i + j < N && board[cnt - j] == i + j)) {
				check = 0;
				break;
			}

		if (check) {
			board[cnt] = i;
			NQueen(board, cnt + 1);
			board[cnt] = 0;
		}
	}
}
int main() {
	scanf("%d", &N);
	vector<int> board(N, -1);
	NQueen(board, 0);
	printf("%d\n", res);
	return 0;
}