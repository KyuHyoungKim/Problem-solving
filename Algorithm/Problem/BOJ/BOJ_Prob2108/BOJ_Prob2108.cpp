#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first != b.first) return a.first > b.first;
	else return a.second < b.second;
}
int main() {
	freopen("input.txt", "r", stdin);
	int N = 0, sum = 0, min = 4000, max = -4000;
	double shift = 0.5;
	int input;
	scanf("%d", &N);
	vector<int> arr(N);
	vector <pair<int, int>> cnt(8001); // cnt, num
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		arr[i] = input;
		sum += input;
		if (input > max) max = input;
		if (input < min) min = input;
		cnt[input+4000].first++;
		cnt[input+4000].second = input;
	}
	sort(arr.begin(), arr.end());
	sort(cnt.begin(), cnt.end(), comp);
	if (sum < 0) shift *= -1;
	printf("%d\n", (int)((double)sum / N + shift));
	printf("%d\n", arr[N / 2]);
	if(cnt[0].first == cnt[1].first) printf("%d\n", cnt[1].second);
	else printf("%d\n", cnt[0].second);
	printf("%d\n", max - min);
	return 0;
}