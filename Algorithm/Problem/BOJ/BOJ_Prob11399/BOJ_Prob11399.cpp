#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, res=0;
	scanf("%d", &N);
	vector<int> time(N);
	for (int i = 0; i < N; i++) scanf("%d", &time[i]);
	sort(time.begin(), time.end());
	for (int i = 1; i < N; i++) time[i] += time[i - 1];
	for (int i = 0; i < N; i++) res += time[i];
	printf("%d\n", res);
	return 0;
}