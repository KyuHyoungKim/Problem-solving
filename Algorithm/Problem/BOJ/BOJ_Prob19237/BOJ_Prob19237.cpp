#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

struct shark_info {
	int y, x, dir;
};
struct trace_info {
	int shark, remain_time;
};
struct pool_info {
	int shark;
	trace_info trace;
};

const int dy[5] = { 0,-1,1,0,0 }, dx[5] = { 0,0,0,-1,1 };
int N, M, K, res = 0, cnt;
vector<vector<pool_info>> pool;
vector<shark_info> sharks;
vector<vector<vector<int>>> sharks_priority;
vector<bool> died;

void init();
void move_shark(int idx);
void set_shark_direction(int idx);
void handle_trace();

int main() {
	freopen("input.txt", "r", stdin);
	init();
	while (res <= 1000) {
		res++;
		for (int i = 1; i <= M; i++) {
			if (died[i]) continue;
			set_shark_direction(i);
			move_shark(i);
		}
		handle_trace();

		if (cnt == 1)
			break;
	}
	if (res > 1000)
		res = -1;
	printf("%d", res);
	return 0;
}

void init() {
	scanf("%d %d %d", &N, &M, &K);
	pool.resize(N, vector<pool_info>(N));
	sharks.resize(M + 1);
	sharks_priority.resize(M + 1, vector<vector<int>>(5, vector<int>(5)));
	died.resize(M + 1);

	cnt = M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &pool[i][j].shark);
			if (pool[i][j].shark) {
				sharks[pool[i][j].shark].y = i;
				sharks[pool[i][j].shark].x = j;

				pool[i][j].trace.shark = pool[i][j].shark;
				pool[i][j].trace.remain_time = K;
			}
		}

	for (int i = 1; i <= M; i++)
		scanf("%d", &sharks[i].dir);

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= 4; j++)
			for (int k = 1; k <= 4; k++)
				scanf("%d", &sharks_priority[i][j][k]);
}

void set_shark_direction(int idx) {
	int Y = sharks[idx].y;
	int X = sharks[idx].x;
	int dir = sharks[idx].dir;
	int dir_next[2] = { 0,0 };
	bool flag[2] = { false, false };
	for (int j = 1; j <= 4; j++) {
		int dir_new = sharks_priority[idx][dir][j];
		int Y_new = Y + dy[dir_new];
		int X_new = X + dx[dir_new];

		if (Y_new < 0 || Y_new >= N || X_new < 0 || X_new >= N)
			continue;

		if (!flag[0] && !pool[Y_new][X_new].trace.shark) {
			flag[0] = true;
			dir_next[0] = dir_new;
			break;
		}
		if (!flag[1] && pool[Y_new][X_new].trace.shark == idx) {
			flag[1] = true;
			dir_next[1] = dir_new;
		}
	}
	for (int j = 0; j < 2; j++)
		if (flag[j]) {
			sharks[idx].dir = dir_next[j];
			break;
		}
}

void move_shark(int idx) {
	if (pool[sharks[idx].y][sharks[idx].x].shark == idx)
		pool[sharks[idx].y][sharks[idx].x].shark = 0;

	sharks[idx].y += dy[sharks[idx].dir];
	sharks[idx].x += dx[sharks[idx].dir];

	if (pool[sharks[idx].y][sharks[idx].x].shark && pool[sharks[idx].y][sharks[idx].x].shark < idx) {
		died[idx] = true;
		cnt--;
	}
	else
		pool[sharks[idx].y][sharks[idx].x].shark = idx;
}

void handle_trace() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (pool[i][j].trace.remain_time) {
				pool[i][j].trace.remain_time--;
				if (!pool[i][j].trace.remain_time)
					pool[i][j].trace.shark = 0;
			}
			if (pool[i][j].shark) {
				pool[i][j].trace.shark = pool[i][j].shark;
				pool[i][j].trace.remain_time = K;
			}
		}
}