#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int paper[128][128] = { 0 };
int res[2] = { 0 };
void findpaper(int start_x, int start_y, int length) {
	int color = paper[start_y][start_x];
	int ret = 1;
	for (int y = start_y; y < start_y + length; y++) {
		for (int x = start_x; x < start_x + length; x++)
		{
			if (paper[y][x] != color) {
				ret = 0;
				break;
			}
		}
		if (!ret) break;
	}
	if (ret) res[color]++;
	else {
		findpaper(start_x, start_y, length / 2);
		findpaper(start_x + length / 2, start_y, length / 2);
		findpaper(start_x, start_y + length / 2, length / 2);
		findpaper(start_x + length / 2, start_y + length / 2, length / 2);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int N = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			scanf("%d", &paper[i][j]);

	findpaper(0, 0, N);
	printf("%d\n%d\n", res[0], res[1]);
	return 0;
}