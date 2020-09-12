#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, res = 0;
	scanf("%d", &N);
	vector<int> nums(N);
	priority_queue<int> pq;
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		pq.push(num);
	}

	while (--N) {
		int num1 = pq.top();
		pq.pop();
		int num2 = pq.top();
		pq.pop();

		pq.push(num1 + num2);
		res += num1 * num2;
	}

	printf("%d", res);
	return 0;
}