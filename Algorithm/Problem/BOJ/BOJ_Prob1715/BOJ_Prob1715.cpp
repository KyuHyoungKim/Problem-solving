#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
class comp {
public:
	bool operator() (const int& a, const int& b) {
		return a > b;
	}
};
int main() {
	freopen("input.txt", "r", stdin);
	int N = 0, num = 0, res = 0;
	int card1 = 0, card2 = 0;
	std::priority_queue <int, std::vector<int>,comp> pq;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		pq.push(num);
	}
	while (pq.size() > 1) {
		card1 = pq.top();
		pq.pop();
		card2 = pq.top();
		pq.pop();
		pq.push(card1 + card2);
		res += card1 + card2;
	}
	printf("%d", res);
	return 0;
}