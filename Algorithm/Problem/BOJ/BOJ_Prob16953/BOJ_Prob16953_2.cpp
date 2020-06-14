#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int A, B, res = -1;
	scanf("%d %d", &A, &B);
	queue<pair<int, int>> q;
	q.push(make_pair(A, 1));
	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		long long a1 = (long long)now * 2, a2 = (long long)now * 10 + 1;
		if (a1 == B || a2 == B) {
			res = cnt + 1;
			break;
		}
		if (a1 < B) q.push(make_pair(a1, cnt + 1));
		if (a2 < B) q.push(make_pair(a2, cnt + 1));
	}
	printf("%d\n", res);
	return 0;
}