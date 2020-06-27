#define _CRT_SECURE_NO_WARNINGS
#define INF 123456789
#include <cstdio>
#include <vector>
using namespace std;
struct Edge {
	int start, end, weight;
};
int main() {
	freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	vector<Edge> Edges;
	vector<long long> dist(N + 1, INF);
	dist[1] = 0;

	for (int i = 0; i < M; i++) {
		Edge input;
		scanf("%d %d %d", &input.start, &input.end, &input.weight);
		Edges.push_back(input);
	}

	bool update = false;
	for (int i = 1; i <= N; i++) {
		update = false;
		for (int j = 0; j < M; j++) {
			Edge Move = Edges[j];
			if (dist[Move.start] == INF) continue;

			if (dist[Move.end] > dist[Move.start] + Move.weight) {
				dist[Move.end] = dist[Move.start] + Move.weight;
				update = true;
			}
		}
		if (!update) break;
	}

	if (update) 
		printf("-1");
	else
		for (int i = 2; i <= N; i++)
		{
			if (dist[i] == INF) printf("-1\n");
			else printf("%d\n", dist[i]);
		}
	return 0;
}