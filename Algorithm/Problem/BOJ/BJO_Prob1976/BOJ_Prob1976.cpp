#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
vector<int> parent;

int find_parent(int a) {
	if (parent[a] == a) 
		return a;
	else 
		return parent[a] = find_parent(parent[a]);
}

void unionize(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main() {
	freopen("input.txt", "r", stdin);

	int N, M, tmp;
	int prev, next;
	scanf("%d %d", &N, &M);
	parent = vector<int>(N + 1);
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			scanf("%d", &tmp);
			if (tmp)
				unionize(i, j);
		}

	scanf("%d", &prev);
	for (int i = 1; i < M; i++) {
		scanf("%d", &next);
		if (find_parent(prev) == find_parent(next))
			prev = next;
		else {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}