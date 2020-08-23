#define _CRT_SECURE_NO_WARNINGS
#define IDX_MAX 10
#define INF 123456789
#include <cstdio>
#include <vector>
using namespace std;

const int dy[5] = { 0, -1, 0, 1, 0 }, dx[5] = { 0, 0, 1, 0, -1 };
vector<int> bulbs(IDX_MAX, 0);

void switch_bulbs(int y, int x, vector<int>& bulb);
int sol_1(int idx, int cnt);
int sol_2(int cnt, vector<int> bulb);

int main() {
	freopen("input.txt", "r", stdin);
	int res;
	for (int i = 0; i < IDX_MAX; i++) {
		for (int j = 0; j < IDX_MAX; j++) {
			char temp;
			scanf("%c", &temp);
			if (temp == 'O')
				bulbs[i] |= 1 << j;
		}
		getchar();
	}

	res = sol_1(0, 0);
	if (res == INF) 
		res = -1;
	
	printf("%d", res);
	return 0;
}

void switch_bulbs(int y, int x, vector<int>& bulb) {
	for (int i = 0; i < 5; i++) {
		int Y = y + dy[i], X = x + dx[i];
		if (Y < 0 || X < 0 || Y >= IDX_MAX || X >= IDX_MAX)
			continue;
		bulb[Y] ^= 1 << X;
	}
}

int sol_1(int idx, int cnt) {
	int a1, a2;
	if (idx == IDX_MAX)
		return sol_2(cnt, bulbs);

	switch_bulbs(0, idx, bulbs);
	a1 = sol_1(idx + 1, cnt + 1);
	switch_bulbs(0, idx, bulbs);
	a2 = sol_1(idx + 1, cnt);
	return (a1 < a2) ? a1 : a2;
}

int sol_2(int cnt, vector<int> bulb) {
	int ret = INF;
	for (int i = 0; i < IDX_MAX - 1; i++)
		for (int j = 0; j < IDX_MAX; j++)
			if (bulb[i] & 1 << j) {
				switch_bulbs(i + 1, j, bulb);
				cnt++;
			}

	if (!bulb[IDX_MAX - 1])
		ret = cnt;

	return ret;
}