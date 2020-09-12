#define _CRT_SECURE_NO_WARNINGS
#define INF 123456791
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int paper[10][10];
int res[6] = { 0 };
int find_max_size(int y, int x);
int sol(int y, int x);
/*
	접근 : 백트래킹
*/
int main() {
	freopen("input.txt", "r", stdin);
	int res = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			scanf("%d", &paper[i][j]);

	res = sol(0, 0);
	if (res >= INF)
		res = -1;
	printf("%d", res);
	return 0;
}

int sol(int y, int x) {
	int ret = INF, ans, size_max = 5;
	while (y <10) {
		if (paper[y][x])
			break;
		x++;
		if (x >= 10) {
			x = 0;
			y++;
		}
	}

	if (y >= 10) {
		ret = 0;
		for (int i = 1; i <= 5; i++)
			ret += res[i];
	}
	else {
		size_max = find_max_size(y, x);
		for (int i = 1; i <= size_max; i++) {
			res[i]++;
			if (res[i] <= 5) {
				for (int a = 0; a < i; a++)
					for (int b = 0; b < i; b++)
						paper[y + a][x + b] = 0;

				ans = sol(y, x);
				ret = min(ans, ret);

				for (int a = 0; a < i; a++)
					for (int b = 0; b < i; b++)
						paper[y + a][x + b] = 1;
			}
			res[i]--;
		}
	}
	return ret;
}

int find_max_size(int y, int x) {
	int size_max = 5;
	for (int i = 0; i < size_max; i++) {
		if (y + i >= 10 || !paper[y + i][x]) {
			size_max = i;
			break;
		}
		for (int j = 0; j < size_max; j++)
			if (x + j >= 10 || !paper[y + i][x + j]) {
				size_max = j;
				break;
			}
	}
	return size_max;
}