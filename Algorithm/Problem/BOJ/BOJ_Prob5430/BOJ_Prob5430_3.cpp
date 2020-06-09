#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
char input[100001];
int main() {
	freopen("input.txt", "r", stdin);
	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%s %d", input, &N);
		string order = input;
		vector<int> arr(N);
		int start = 0, end = N - 1, k = 1;

		getchar(); getchar();
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			getchar();
		}
		if (!N) scanf("%s", input);

		for (int i = 0; i < order.size(); i++) {
			if (order[i] == 'R') k *= -1;
			else if (order[i] == 'D') {
				if (k > 0) start++;
				else end--;
			}
		}

		if (start - end > 1) printf("error\n");
		else {
			printf("[");
			if (k > 0) for (int i = start; i <= end; i++)
			{
				printf("%d", arr[i]);
				if (i != end) printf(",");
			}
			else for (int i = end; i >= start; i--)
			{
				printf("%d", arr[i]);
				if (i != start) printf(",");
			}
			printf("]\n");
		}
	}
	return 0;
}