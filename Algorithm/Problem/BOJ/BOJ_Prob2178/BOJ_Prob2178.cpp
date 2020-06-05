#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int N, M, res = 0;
	int dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };
	scanf("%d %d", &N, &M);
	char input[101];
	vector<string> maze(N);
	vector<vector<char>> checked(N, vector<char>(M));
	for (int i = 0; i < N; i++) {
		scanf("%s", input);
		maze[i] = input;
	}
	queue<pair<int, int>> curr;
	curr.push(make_pair(0, 0));
	checked[0][0] = '1';
	while (!curr.empty()) {
		queue<pair<int, int>> Next;
		res++;
		while (!curr.empty()) {
			pair<int, int> now = curr.front();
			curr.pop();
			for (int i = 0; i < 4; i++) {
				int Y = now.first + dy[i];
				int X = now.second + dx[i];
				if (X == M - 1 && Y == N - 1) {
					printf("%d\n", res + 1);
					return 0;
				}
				if (X >= 0 && X < M && Y >= 0 && Y < N && maze[Y][X] == '1' && !checked[Y][X]) {
					Next.push(make_pair(Y, X));
					checked[Y][X] = '1';
				}
			}
		}
		curr = Next;
	}
	printf("%d\n", res);
	return 0;
}