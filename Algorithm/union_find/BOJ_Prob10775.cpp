#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

int G, P;
vector<int> root;

int find(int x) {
	if (root[x] == x) return x;
	else return root[x] = find(root[x]);
}
void unionize(int x, int y) {
	x = find(x);
	y = find(y);
	root[x] = y;
}
int main() {
	freopen("input.txt", "r", stdin);
	int res = 0;
	scanf("%d %d", &G, &P);
	root.resize(G + 1, 0);
	for (int i = 0; i <= G; i++)
		root[i] = i;
	while (P--) {
		int g;
		scanf("%d", &g);
		int finded_root = find(g);
		if (!finded_root)
			break;
		else {
			res++;
			unionize(finded_root, finded_root - 1);
		}
	}
	printf("%d", res);
	return 0;
}