#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <set>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int T, N, num;
	char order;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		multiset<int> pq;
		while (N--) {
			getchar();
			scanf("%c %d", &order, &num);
			if (order == 'I') pq.insert(num);
			else if (pq.size()) {
				if (num > 0) pq.erase(--pq.end());
				else pq.erase(pq.begin());
			}
		}
		if (pq.size()) printf("%d %d\n", *(--pq.end()), *pq.begin());
		else printf("EMPTY\n");
	}

	return 0;
}