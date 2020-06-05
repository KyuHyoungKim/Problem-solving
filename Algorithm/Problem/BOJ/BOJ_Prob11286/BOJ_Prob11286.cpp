#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct comp {
	bool operator()(const int& a, const int& b) {
		long long A = a, B = b;
		if (A * A != B * B) return A * A > B* B;
		else return a > b;
	}
};
int main() {
	freopen("input.txt", "r", stdin);
	int N, input;
	scanf("%d", &N);
	priority_queue<int, vector<int>, comp> pq;
	while (N--) {
		scanf("%d", &input);
		if (input) pq.push(input);
		else if (pq.empty()) printf("0\n");
		else {
			printf("%d\n", pq.top());
			pq.pop();
		}
	}
	return 0;
}