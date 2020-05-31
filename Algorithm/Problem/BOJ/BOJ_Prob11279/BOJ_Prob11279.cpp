#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	priority_queue<int,vector<int>> pq;
	int N, num;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &num);
		if (num)
			pq.push(num);
		else if (!pq.empty()) {
			printf("%d\n", pq.top());
			pq.pop();
		}
		else printf("0\n");
	}
	return 0;
}