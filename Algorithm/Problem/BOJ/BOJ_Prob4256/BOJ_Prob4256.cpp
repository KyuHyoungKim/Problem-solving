#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
vector<int> pre_order, in_order, in_index, post_order;
void print_post_order(int pre_start, int pre_end, int in_start, int in_end, int post_start, int post_end) {
	if (pre_start > pre_end || in_start > in_end || post_start > post_end) return;
	int root = pre_order[pre_start];
	int in_root_idx = in_index[root];
	post_order[post_end] = root;
	print_post_order(
		pre_start + 1, pre_start + in_root_idx - in_start,
		in_start, in_root_idx - 1,
		post_start, post_start + in_root_idx - in_start - 1);
	print_post_order(
		pre_start + 1 + in_root_idx - in_start, pre_end,
		in_root_idx + 1, in_end,
		post_start + in_root_idx - in_start, post_end - 1);
}

int main() {
	freopen("input.txt", "r", stdin);
	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		pre_order.resize(N);
		in_order.resize(N);
		in_index.resize(N);
		post_order.resize(N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &pre_order[i]);
			pre_order[i]--;
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &in_order[i]);
			in_order[i]--;
		}
		for (int i = 0; i < N; i++)
			in_index[in_order[i]] = i;

		print_post_order(0, N - 1, 0, N - 1, 0, N - 1);
		for (int i = 0; i < N; i++)
			printf("%d ", post_order[i] + 1);
		printf("\n");
	}
	return 0;
}