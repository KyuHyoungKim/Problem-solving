#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int dy[4] = { 0, 1, 0, -1 }, dx[4] = { 1,0,-1,0 };
// 0 : 오른쪽
// 1 : 아래
// 2 : 왼쪽
// 3 : 위
int N, K, L, dir = 0, time = 0, ord = 0;
pair<int, int> Head;
vector<vector<int>> Map;
vector<pair<int, char>> order;
queue<pair<int, int>> Tail;
void init();

int main() {
	freopen("input.txt", "r", stdin);
	init();
	while (1) {
		time++;
		if (ord < L && order[ord].first < time) {
			if (order[ord].second == 'D')
				dir = (dir + 1) % 4;
			else {
				dir--;
				if (dir < 0)
					dir = 3;
			}
			ord++;
		}
		
		Head.first += dy[dir];
		Head.second += dx[dir];

		if (Head.first < 0 || Head.first >= N || Head.second < 0 || Head.second >= N || Map[Head.first][Head.second] == 2)
			break;

		if (!Map[Head.first][Head.second]) {
			Map[Tail.front().first][Tail.front().second] = 0;
			Tail.pop();
		}

		Map[Head.first][Head.second] = 2;
		Tail.push(Head);
	}

	printf("%d", time);
	return 0;
}

void init() {
	scanf("%d %d", &N, &K);
	vector<vector<int>> Map_init(N, vector<int>(N));

	for (int i = 0; i < K; i++) {
		int Y, X;
		scanf("%d %d", &Y, &X);
		Map_init[Y - 1][X - 1] = 1;
	}
	Map_init[0][0] = 2;
	Map.swap(Map_init);

	Head.first = Head.second = 0;
	Tail.push(Head);

	scanf("%d", &L);
	vector<pair<int, char>> order_init(L);
	for (int i = 0; i < L; i++)
		scanf("%d %c", &order_init[i].first, &order_init[i].second);
	order.swap(order_init);
}
