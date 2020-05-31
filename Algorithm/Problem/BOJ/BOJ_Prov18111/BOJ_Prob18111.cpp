#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int N, M, B, start = 256, end = 0;
	scanf("%d %d %d", &N, &M, &B);
	vector<vector<int>> field(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &field[i][j]);
			if (field[i][j] < start) start = field[i][j];
			if (field[i][j] > end) end = field[i][j];
		}
	int res = start, min_time = 1e9;

	for(int h = start; h <=end;h++)
	{
		int time = 0;
		int blocks = B;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) 
			{
				if (field[i][j] > h) {
					time += (field[i][j] - h) * 2;
					blocks += field[i][j] - h;
				}
				else if (field[i][j] < h) {
					time += h - field[i][j];
					blocks -= h - field[i][j];
				}
			}
		if (blocks < 0) break;
		if (time <= min_time) {
			min_time = time;
			res = h;
		}
		else
			break;
	}
	printf("%d %d\n", min_time, res);
	return 0;
}