#define _CRT_SECURE_NO_WARNINGS
#define IDX_MAX 101

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

class shark {
public:
	int y = 0, x = 0;
	int speed = 0, direc = 0, size = 0;
};

const int dy[5] = { 0, -1,1,0,0 }, dx[5] = { 0, 0,0,1,-1 };
int R, C, M, res = 0, board[IDX_MAX][IDX_MAX];
vector<shark> sharks;
vector<bool> checked;

void init();
void fishing(int idx);
void compare_shark_size(int idx);
void move_shark();
void set_shark_info(const int** dxy, int** position, int** dir_max, int* idx);
void set_position(const int** dxy, int** position, int** dir_max, int* idx);

int main() {
	freopen("input.txt", "r", stdin);
	init();
	for (int i = 1; i <= C; i++) {
		fishing(i);
		move_shark();
	}
	printf("%d", res);
	return 0;
}

void init() {
	scanf("%d %d %d", &R, &C, &M);
	sharks.resize(M + 1);
	checked.resize(M + 1);
	memset(board, 0, sizeof(board));
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d %d %d", &sharks[i].y, &sharks[i].x, &sharks[i].speed, &sharks[i].direc, &sharks[i].size);
		board[sharks[i].y][sharks[i].x] = i;
	}
}

void fishing(int idx) {
	for (int i = 1; i <= R; i++)
		if (board[i][idx]) {
			res += sharks[board[i][idx]].size;
			checked[board[i][idx]] = true;
			board[i][idx] = 0;
			return;
		}
}

void compare_shark_size(int idx) {
	int idx2 = board[sharks[idx].y][sharks[idx].x];
	if (idx < idx2) {
		board[sharks[idx].y][sharks[idx].x] = idx;
		return;
	}

	if (sharks[idx2].size < sharks[idx].size) {
		checked[idx2] = true;
		board[sharks[idx].y][sharks[idx].x] = idx;
	}
	else
		checked[idx] = true;
}

void move_shark() {
	for (int i = 1; i <= M; i++) {
		if (checked[i]) continue;
		if (board[sharks[i].y][sharks[i].x] == i)
			board[sharks[i].y][sharks[i].x] = 0;

		const int* dxy;
		int* position, *dir_max;
		set_shark_info(&dxy, &position, &dir_max, &i);
		set_position(&dxy, &position, &dir_max, &i);
		compare_shark_size(i);
	}
}

void set_shark_info(const int** dxy, int** position, int** dir_max, int* idx) {
	if (sharks[*idx].direc > 2) {
		*position = &sharks[*idx].x;
		*dir_max = &C;
		*dxy = dx;
	}
	else {
		*position = &sharks[*idx].y;
		*dir_max = &R;
		*dxy = dy;
	}
}

void set_position(const int** dxy, int** position, int** dir_max, int* idx) {
	**position += (*dxy)[sharks[*idx].direc] * (sharks[*idx].speed);
	while (**position <= 0 || **position > * *dir_max) {
		if (**position <= 0)
			**position = (**position - 2) * -1;
		else
			**position = **dir_max * 2 - **position;

		if (sharks[*idx].direc % 2)
			sharks[*idx].direc++;
		else
			sharks[*idx].direc--;
	}
}