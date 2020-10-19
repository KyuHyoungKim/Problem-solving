#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

int find_parent(vector<int>& parent, int set) {
	if (parent[set] == set) return set;
	else return parent[set] = find_parent(parent, parent[set]);
}

void unionize(vector<int>& parent, int& set1, int& set2) {
	set1 = find_parent(parent, set1);
	set2 = find_parent(parent, set2);
	if (set1 < set2)
		parent[set2] = set1;
	else
		parent[set1] = set2;
}

int main() {
	freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> parent(N + 1);
	for (int i = 0; i <= N; i++)
		parent[i] = i;
	while (M--) {
		int order, set1, set2;
		scanf("%d %d %d", &order, &set1, &set2);
		if (order) {
			if (find_parent(parent, set1) == find_parent(parent, set2))
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
			unionize(parent, set1, set2);
	}
	return 0;
}