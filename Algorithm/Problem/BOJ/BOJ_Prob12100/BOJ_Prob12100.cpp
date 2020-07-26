#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int res = 0;
vector<vector<int>> up(vector<vector<int>> board) {
	int size = board.size();
	bool check = true;
	vector<vector<int>> ret(size, vector<int>(size));
	for (int i = 0; i < size; i++) {
		int cnt = 0;
		for (int j = 0; j < size; j++) {
			int num = board[j][i];
			if (num == 0) continue;
			if (cnt > 0 && ret[cnt - 1][i] == num && check) {
				ret[cnt - 1][i] *= 2;
				check = false;
				if (ret[cnt - 1][i] > res) res = ret[cnt - 1][i];
			}
			else {
				ret[cnt][i] = num;
				cnt++;
				check = true;
			}
		}
	}
	return ret;
}
vector<vector<int>> down(vector<vector<int>> board) {
	int size = board.size();
	bool check = true;
	vector<vector<int>> ret(size, vector<int>(size));
	for (int i = size - 1; i >= 0; i--) {
		int cnt = size - 1;
		for (int j = size - 1; j >= 0; j--) {
			int num = board[j][i];
			if (num == 0) continue;
			if (cnt < size - 1 && ret[cnt + 1][i] == num && check) {
				ret[cnt + 1][i] *= 2;
				check = false;
				if (ret[cnt + 1][i] > res) res = ret[cnt + 1][i];
			}
			else {
				ret[cnt][i] = num;
				cnt--;
				check = true;
			}
		}
	}
	return ret;
}
vector<vector<int>> left(vector<vector<int>> board) {
	int size = board.size();
	bool check = true;
	vector<vector<int>> ret(size, vector<int>(size));
	for (int i = 0; i < size; i++) {
		int cnt = 0;
		for (int j = 0; j < size; j++) {
			int num = board[i][j];
			if (num == 0) continue;
			if (cnt > 0 && ret[i][cnt - 1] == num && check) {
				ret[i][cnt - 1] *= 2;
				check = false;
				if (ret[i][cnt - 1] > res) res = ret[i][cnt - 1];
			}
			else {
				ret[i][cnt] = num;
				cnt++;
				check = true;
			}
		}
	}
	return ret;
}
vector<vector<int>> right(vector<vector<int>> board) {
	int size = board.size();
	bool check = true;
	vector<vector<int>> ret(size, vector<int>(size));
	for (int i = size - 1; i >= 0; i--) {
		int cnt = size - 1;
		for (int j = size - 1; j >= 0; j--) {
			int num = board[i][j];
			if (num == 0) continue;
			if (cnt < size - 1 && ret[i][cnt + 1] == num && check) {
				ret[i][cnt + 1] *= 2;
				check = false;
				if (ret[i][cnt + 1] > res) res = ret[i][cnt + 1];
			}
			else {
				ret[i][cnt] = num;
				cnt--;
				check = true;
			}
		}
	}
	return ret;
}

void play_game(vector<vector<int>> board, int count) {
	if (count > 4) return;
	play_game(up(board), count + 1);
	play_game(down(board), count + 1);
	play_game(left(board), count + 1);
	play_game(right(board), count + 1);
}

int main() {
	freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	vector<vector<int>> board(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &board[i][j]);
			if (res < board[i][j]) res = board[i][j];
		}
	play_game(board, 0);
	printf("%d", res);
	return 0;
}