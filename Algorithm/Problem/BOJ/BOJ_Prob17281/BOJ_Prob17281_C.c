#define _CRT_SECURE_NO_WARNINGS
#define Out 0
#define Homerun 4

#include <stdio.h>
#include <stdbool.h>

int N;
int players[50][10] = { 0 };
int order[9] = { 0, 0, 0, 1, 0 };

int sol(int check, int cnt);
int play();

int main() {
	freopen("input.txt", "r", stdin);
	int res = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 1; j <= 9; j++)
			scanf("%d", &players[i][j]);
	res = sol(3, 0);
	printf("%d", res);
	return 0;
}

int sol(int check, int cnt) {
	int ret = 0, a;
	if (cnt == 9)
		return play();

	if (cnt == 3)
		ret = sol(check, cnt + 1);
	else
		for (int i = 2; i <= 9; i++) {
			if (1 << i & check)
				continue;
			order[cnt] = i;
			a = sol(check | 1 << i, cnt + 1);
			if (ret < a)
				ret = a;
			order[cnt] = 0;
		}

	return ret;
}

int play() {
	bool base[3] = { false };
	int score = 0;
	int idx = 0;
	for (int n = 0; n < N; n++) {
		int out = 0;
		for (int i = 0; i < 3; i++)
			base[i] = false;

		for (; out < 3; idx++) {
			if (idx > 8)
				idx = 0;

			int action = players[n][order[idx]];
			if (action == Out)
				out++;
			else if (action == Homerun) {
				for (int i = 2; i >= 0; i--)
					if (base[i]) {
						score++;
						base[i] = false;
					}
				score++;
			}
			else {
				for (int i = 0; i < action; i++)
					if (base[2 - i]) {
						score++;
						base[2 - i] = false;
					}

				for (int i = 0; i < 3 - action; i++)
					if (base[2 - action - i]) {
						base[2 - action - i + action] = true;
						base[2 - action - i] = false;
					}
				base[action - 1] = true;
			}
		}
	}
	return score;
}