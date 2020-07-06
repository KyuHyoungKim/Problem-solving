#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
vector<int> in_order, post_order, in_order_index;

void Find_Root(int in_start, int in_end,int post_start, int post_end) {
	if (post_start > post_end || in_start > in_end)
		return;
	
	int root = post_order[post_end];
	printf("%d ", root + 1);

	int m = in_order_index[root];

	Find_Root(in_start, m - 1, post_start, post_start + m - in_start - 1);
	Find_Root(m + 1, in_end, post_start + m - in_start, post_end - 1);
}

int main(void) {
	freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	in_order.resize(N);
	in_order_index.resize(N);
	post_order.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &in_order[i]);
		in_order[i]--;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &post_order[i]);
		post_order[i]--;
	}
	for (int i = 0; i < N; i++) 
		in_order_index[in_order[i]] = i;
	Find_Root(0, N - 1, 0, N - 1);
	return 0;
}