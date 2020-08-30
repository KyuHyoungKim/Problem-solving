#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int main() {
	freopen("input.txt", "r",stdin);
	int N;
	scanf("%d", &N);
	priority_queue<int, vector<int>, less<int>> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	max_heap.push(-123456791);
	min_heap.push(1234567891);
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		if (max_heap.size() == min_heap.size())
			max_heap.push(num);
		else
			min_heap.push(num);

		if (max_heap.top() > min_heap.top()) {
			max_heap.push(min_heap.top());
			min_heap.push(max_heap.top());
			max_heap.pop();
			min_heap.pop();
		}
		printf("%d\n", max_heap.top());
	}
	return 0;
}