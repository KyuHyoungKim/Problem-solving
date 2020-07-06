#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
vector<int> pre_order, in_index;
void print_post_order(int pre_start, int pre_end, int in_start, int in_end) {
	if (pre_start > pre_end || in_start > in_end) return;
	int root = pre_order[pre_start];
	int in_root_idx = in_index[root];

	print_post_order(
		pre_start + 1, pre_start + in_root_idx - in_start,
		in_start, in_root_idx - 1);
	print_post_order(
		pre_start + 1 + in_root_idx - in_start, pre_end,
		in_root_idx + 1, in_end);

	printf("%d ", root);
}

int main() {
	freopen("input.txt", "r", stdin);
	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		pre_order.resize(N + 1);
		in_index.resize(N + 1);
		for (int i = 0; i < N; i++) scanf("%d", &pre_order[i]);

		for (int i = 0; i < N; i++) {
			int temp;
			scanf("%d", &temp);
			in_index[temp] = i;
		}

		print_post_order(0, N - 1, 0, N - 1);
		printf("\n");
	}
	return 0;
}