#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int A, B, res = 1, finded = 0;
	scanf("%d %d", &A, &B);
	queue<int> q;
	q.push(A);
	while (!q.empty()) {
		queue<int> Next;
		res++;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			long long a1 = (long long)now * 2, a2 = (long long)now * 10 + 1;
			if (a1 == B || a2 == B) finded = 1;
			if (a1 < B) Next.push(a1);
			if (a2 < B) Next.push(a2);
		}
		if (finded) break;
		q = Next;
	}
	if (finded)
		printf("%d", res);
	else
		printf("-1", res);
	return 0;
}