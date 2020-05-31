#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
vector<int> dp[1000001];
vector<int> sol(vector<int> arr) {
	int N = arr[0];
	if (N == 1) return arr;
	if (!dp[N].empty()) return dp[N];
	vector <int> a1 = { 123456789,123456789 }, a2 = a1, a3 = a1, ret;
	if (N % 3 == 0) {
		arr[0] = N / 3;
		a1 = sol(arr);
	}
	if (arr[0] % 2 == 0) {
		arr[0] = N / 2;
		a2 = sol(arr);
	}
	arr[0] = N - 1;
	a3 = sol(arr);
	ret = (a1[1] <= a2[1]) ? a1 : a2;
	if (ret[1] > a3[1]) ret = a3;

	ret.push_back(N);
	ret[1]++;
	dp[N] = ret;
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	int N = 0;
	scanf("%d", &N);
	vector<int> res = { N,0,1 };
	res = sol(res);
	printf("%d\n", res[1]);
	for (int i = res.size() - 1; i >= 2; --i) printf("%d ", res[i]);
	return 0;
}