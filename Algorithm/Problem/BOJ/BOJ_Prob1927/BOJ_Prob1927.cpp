#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
class comp {
public:
	bool operator()(const int& a,const int& b) {
		return a > b;
	}
};
int main() {
	freopen("input.txt", "r", stdin);
	int N = 0, num = 0;
	scanf("%d", &N);
	priority_queue<int, vector<int>,comp> pq;
	while (N--) {
		scanf("%d", &num);
		if (!num) {
			if (pq.empty()) printf("0\n");
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else pq.push(num);
	}
	return 0;
}