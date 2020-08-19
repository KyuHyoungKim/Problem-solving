#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	vector<int> DP(N + 1);
	DP[1] = 1;
	DP[2] = 2;
	
	for (int i = 3; i <= N; i++)
		DP[i] = (DP[i - 1] + DP[i - 2]) % 15746;

	printf("%d", DP[N]);
	return 0;
}