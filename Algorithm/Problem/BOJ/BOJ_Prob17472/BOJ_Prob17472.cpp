#define _CRT_SECURE_NO_WARNINGS
#define min(a,b) (a<b)?a:b
#define INF 1234567891
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct pair {
	int first;
	int second;
}pair;
typedef struct tuple {
	int first;
	int second;
	int third;
}tuple;
typedef struct priority_queue {
	tuple edges[36];
	int idx;
}priority_queue;

const int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
int N, M;
int Map[10][10] = { 0 };
int graph[7][7] = { 0 };
int island_cnt = 0;
int parent[7];
pair island_range_Y[7];
pair island_range_X[7];

pair make_pair(int a, int b);
tuple make_tuple(int a, int b, int c);
void BFS_search_island(int y, int x);
void Find_Bridge(int island_num);
void Build_Bridge(int i, int j, int* last_island, int* length);
void swap_int(int* a, int* b);
void swap_tuple(tuple* a, tuple* b);
void push(priority_queue* pq, tuple edge);
void pop(priority_queue* pq);
tuple top(priority_queue* pq);
int find_parent(int X);
void unionize(int idx1, int idx2);

int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	int res = 0;
	priority_queue pq;
	memset(&pq, 0, sizeof(pq));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &Map[i][j]);
			Map[i][j] *= 10;
		}

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			if (Map[i][j] == 10) {
				island_cnt++;
				island_range_Y[island_cnt] = make_pair(10, -1);
				island_range_X[island_cnt] = make_pair(10, -1);
				BFS_search_island(i, j);
			}

	for (int i = 1; i <= island_cnt; i++) {
		parent[i] = i;
		for (int j = 1; j <= island_cnt; j++)
			graph[i][j] = INF;
	}
	
	for (int i = 1; i <= island_cnt; i++)
		Find_Bridge(i);

	for(int i = 1 ; i <= island_cnt; i++)
		for (int j = 1; j <= island_cnt; j++) {
			if (i == j || graph[i][j] >= INF)
				continue;
			push(&pq, make_tuple(i, j, graph[i][j]));
		}

	while (pq.idx > 0) {
		int node1 = top(&pq).first;
		int node2 = top(&pq).second;
		int dist = top(&pq).third;
		pop(&pq);
		if (find_parent(node1) == find_parent(node2))
			continue;
		res += dist;
		unionize(node1, node2);
	}
	for(int i = 1 ; i <= island_cnt; i++)
		if (find_parent(i) != 1) {
			res = -1;
			break;
		}
	printf("%d", res);
	return 0;
}

pair make_pair(int a, int b) {
	pair ret;
	ret.first = a;
	ret.second = b;
	return ret;
}
tuple make_tuple(int a, int b, int c) {
	tuple ret;
	ret.first = a;
	ret.second = b;
	ret.third = c;
	return ret;
}
void BFS_search_island(int y, int x) {
	pair queue[100] = { 0 };
	bool visited[10][10] = { false };
	int front = 0;
	int idx = 1;
	queue[0] = make_pair(y, x);
	visited[y][x] = true;

	while (idx > front) {
		int Y = queue[front].first;
		int X = queue[front].second;
		front++;
		if (Map[Y][X] < 10) continue;
		Map[Y][X] = island_cnt;
		if (island_range_Y[island_cnt].first > Y)
			island_range_Y[island_cnt].first = Y;
		if (island_range_Y[island_cnt].second < Y)
			island_range_Y[island_cnt].second = Y;
		if (island_range_X[island_cnt].first > X)
			island_range_X[island_cnt].first = X;
		if (island_range_X[island_cnt].second < X)
			island_range_X[island_cnt].second = X;

		for (int i = 0; i < 4; i++) {
			int Y_Next = Y + dy[i];
			int X_Next = X + dx[i];

			if (Y_Next < 0 || Y_Next >= N || X_Next < 0 || X_Next >= M || visited[Y_Next][X_Next])
				continue;
			queue[idx++] = make_pair(Y_Next, X_Next);
			visited[Y_Next][X_Next] = true;
		}

	}
}
void Find_Bridge(int island_num) {
	int last_island ,length = 0;
	for (int i = 0; i < N; i++) {
		last_island = 0;
		length = 0;
		for (int j = 0; j < M; j++)
			Build_Bridge(i, j, &last_island, &length);
	}

	for (int j = 0; j < M; j++) {
		last_island = 0;
		length = 0;
		for (int i = 0; i < N; i++)
			Build_Bridge(i, j, &last_island, &length);
	}
}
void Build_Bridge(int i, int j, int* last_island, int* length) {
	if (!Map[i][j]) {
		if (*last_island)
			(*length)++;
	}
	else {
		if (*length > 1 && *last_island != Map[i][j]) {
			graph[*last_island][Map[i][j]] = min(*length, graph[*last_island][Map[i][j]]);
			graph[Map[i][j]][*last_island] = min(*length, graph[Map[i][j]][*last_island]);
		}
		*last_island = Map[i][j];
		*length = 0;
	}
}
void swap_int(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void swap_tuple(tuple* a, tuple* b) {
	tuple temp = *a;
	*a = *b;
	*b = temp;
}
void push(priority_queue* pq, tuple edge) {
	pq->edges[pq->idx] = edge;

	int now = pq->idx++;
	int parent_node = (now - 1) / 2;

	while (now > 0 && pq->edges[now].third < pq->edges[parent_node].third) {
		swap_tuple(&pq->edges[now], &pq->edges[parent_node]);
		now = parent_node;
		parent_node = (now - 1) / 2;
	}
}
void pop(priority_queue* pq) {
	pq->idx--;
	pq->edges[0] = pq->edges[pq->idx];
	pq->edges[pq->idx] = make_tuple(0, 0, 0);

	int now = 0, Lchild = 1, Rchild = 2;
	int target = now;
	while (1) {
		if (Lchild < pq->idx && pq->edges[target].third > pq->edges[Lchild].third)
			target = Lchild;
		if (Rchild < pq->idx && pq->edges[target].third > pq->edges[Rchild].third)
			target = Rchild;
		if (now == target)
			break;
		swap_tuple(&pq->edges[target], &pq->edges[now]);
		now = target;
		Lchild = now * 2 + 1;
		Rchild = Lchild + 1;
	}

}
tuple top(priority_queue* pq) {
	return pq->edges[0];
}
int find_parent(int X) {
	if (parent[X] == X)
		return X;
	else
		return parent[X] = find_parent(parent[X]);
}
void unionize(int idx1, int idx2) {
	idx1 = find_parent(idx1);
	idx2 = find_parent(idx2);
	if (idx1 > idx2)
		swap_int(&idx1, &idx2);
	parent[idx2] = idx1;
}