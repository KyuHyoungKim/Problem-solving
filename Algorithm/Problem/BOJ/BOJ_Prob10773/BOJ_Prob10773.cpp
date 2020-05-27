#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N = 0, sum = 0, input;
	vector<int> nums;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &input);
		if (input) {
			sum += input;
			nums.push_back(input);
		}
		else if (!nums.empty()) {
			sum -= nums.back();
			nums.pop_back();
		}
	}
	printf("%d\n", sum);
	return 0;
}