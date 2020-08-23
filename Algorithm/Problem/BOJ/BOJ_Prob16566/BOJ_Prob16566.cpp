#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> parents;
int find_parent(int idx) {
	if (parents[idx] == idx) return idx;
	else return parents[idx] = find_parent(parents[idx]);
}
void unionize(int idx1, int idx2) {
	idx1 = find_parent(idx1);
	idx2 = find_parent(idx2);
	if (idx1 < idx2) swap(idx1, idx2);
	parents[idx2] = idx1;
}
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, K, num;
	scanf("%d %d %d", &N, &M, &K);
	vector<int> cards(M+1);
	parents.resize(M+1);
	cards[0] = 123456789;
	for (int i = 1; i <= M; i++) {
		scanf("%d", &cards[i]);
		parents[i] = i;
	}
	sort(cards.begin(), cards.end());
	while (K--) {
		scanf("%d", &num);
		int idx = upper_bound(cards.begin(), cards.end(), num) - cards.begin();
		idx = find_parent(idx);
		printf("%d\n", cards[idx]);
		unionize(idx, idx + 1);
	}
	return 0;
}
