#define _CRT_SECURE_NO_WARNINGS
#define INF 1234567891
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Edge_info {
	int node;
	int cost;
	int dist;
}Edge;

typedef struct Priority_Queue {
	Edge* Edges;
	int size;
	int cap;
}PQ;

int edge_cnt[101];
Edge graph[101][10001];
int visited[101][10001];
PQ pq;

inline Edge make_Edge(int node, int cost, int dist) {
	Edge ret;
	ret.node = node;
	ret.cost = cost;
	ret.dist = dist;
	return ret;
}

inline void swap(Edge* a, Edge* b) {
	Edge temp = *a;
	*a = *b;
	*b = temp;
}

inline void push(PQ* pq, Edge E) {
	if (pq->size >= pq->cap) {
		pq->cap *= 2;
		pq-> Edges = realloc(pq->Edges, sizeof(Edge) * pq->cap);
	}

	pq->Edges[pq->size] = E;

	int now = pq->size++;
	int parent = (now - 1) / 2;

	while (now && pq->Edges[now].dist < pq->Edges[parent].dist) {
		swap(&pq->Edges[now], &pq->Edges[parent]);
		now = parent;
		parent = (now - 1) / 2;
	}
}

inline void pop(PQ* pq) {
	pq->size--;
	pq->Edges[0] = pq->Edges[pq->size];
	pq->Edges[pq->size].cost = pq->Edges[pq->size].dist = pq->Edges[pq->size].node = 0;

	int now = 0, Lchild = 1, Rchild = 2;
	int target = now;

	while (1) {
		if (Lchild < pq->size && pq->Edges[target].dist > pq->Edges[Lchild].dist)
			target = Lchild;
		if (Rchild < pq->size && pq->Edges[target].dist > pq->Edges[Rchild].dist)
			target = Rchild;
		if (target == now)
			break;

		swap(&pq->Edges[target], &pq->Edges[now]);
		now = target;
		Lchild = now * 2 + 1;
		Rchild = Lchild + 1;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M, K, res = INF;
		scanf("%d %d %d", &N, &M, &K);

		memset(edge_cnt, 0, sizeof(edge_cnt));
		memset(graph, 0, sizeof(graph));
		memset(&pq, 0, sizeof(PQ));
		pq.cap = 1000;
		pq.Edges = malloc(sizeof(Edge) * pq.cap);

		for (int i = 1; i <= N; i++)
			for (int j = 0; j <= M; j++)
				visited[i][j] = INF;

		for (int i = 0; i < K; i++) {
			int u, v, c, d;
			scanf("%d %d %d %d", &u, &v, &c, &d);
			graph[u][edge_cnt[u]].node = v;
			graph[u][edge_cnt[u]].cost = c;
			graph[u][edge_cnt[u]].dist = d;
			edge_cnt[u]++;
		}

		push(&pq, make_Edge(1, 0, 0));
		while (pq.size > 0) {
			int node = pq.Edges[0].node;
			int cost = pq.Edges[0].cost;
			int dist = pq.Edges[0].dist;

			pop(&pq);
			if (node == N) {
				res = dist;
				break;
			}

			for (int i = 0; i < edge_cnt[node]; i++) {
				int node_new = graph[node][i].node;
				int cost_new = graph[node][i].cost + cost;
				int dist_new = graph[node][i].dist + dist;
				if (cost_new > M)
					continue;
				if (visited[node_new][cost_new] <= dist_new)
					continue;

				push(&pq, make_Edge(node_new, cost_new, dist_new));
				for (int i = cost_new; i <= M; i++) {
					if (visited[node_new][i] <= dist_new)
						break;
					visited[node_new][i] = dist_new;
				}
			}
		}
		if (res == INF)
			printf("Poor KCM\n");
		else
			printf("%d\n", res);
		free(pq.Edges);
	}
	return 0;
}