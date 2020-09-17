#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
const int dy[5] = { 0,0,0,-1,1 }, dx[5] = { 0,1,-1,0,0 };
struct dice {
	int top = 0;
	int bottom = 0;
	int up = 0;
	int down = 0;
	int right = 0;
	int left = 0;
};

void rotate(dice& Dice, int dir) {
	int temp = Dice.top;
	int* first, * second, * third, * forth;
	first = &Dice.top;
	third = &Dice.bottom;

	if (dir == 1) {
		second = &Dice.left;
		forth = &Dice.right;
	}
	else if (dir == 2) {
		second = &Dice.right;
		forth = &Dice.left;
	}
	else if (dir == 3) {
		second = &Dice.down;
		forth = &Dice.up;
	}
	else {
		second = &Dice.up;
		forth = &Dice.down;
	}
	*first = *second;
	*second = *third;
	*third = *forth;
	*forth = temp;
}
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, K;
	pair<int, int> dice_pos;
	dice Dice;
	scanf("%d %d %d %d %d", &N, &M, &dice_pos.first, &dice_pos.second, &K);
	vector<vector<int>> Map(N, vector<int>(M));
	vector<int> dir(K);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &Map[i][j]);
	for (int i = 0; i < K; i++)
		scanf("%d", &dir[i]);

	for (int i = 0; i < K; i++) {
		int Y = dice_pos.first + dy[dir[i]];
		int X = dice_pos.second + dx[dir[i]];
		if (Y >= N || Y < 0 || X >= M || X < 0)
			continue;
		dice_pos.first = Y;
		dice_pos.second = X;
		rotate(Dice, dir[i]);

		if (Map[dice_pos.first][dice_pos.second]) {
			Dice.bottom = Map[dice_pos.first][dice_pos.second];
			Map[dice_pos.first][dice_pos.second] = 0;
		}
		else
			Map[dice_pos.first][dice_pos.second] = Dice.bottom;
		printf("%d\n", Dice.top);
	}

	return 0;
}