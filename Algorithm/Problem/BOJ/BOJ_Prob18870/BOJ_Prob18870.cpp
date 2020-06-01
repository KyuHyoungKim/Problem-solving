#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool comp1(const vector<int>& a, const vector<int>& b) {
	return a[0] < b[0];
}
bool comp2(const vector<int>& a, const vector<int>& b) {
	return a[1] < b[1];
}
int main() {
	freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	vector<vector<int>> point(N, vector<int>(3)); // value ,initial index, res
	for (int i = 0; i < N; i++) {
		scanf("%d", &point[i][0]);
		point[i][1] = i;
	}
	sort(point.begin(), point.end(), comp1);
	int New_value = 0;
	point[0][2] = New_value;
	for (int i = 1; i < N; i++) {
		if (point[i][0] > point[i - 1][0]) New_value++;
		point[i][2] = New_value;
	}
	sort(point.begin(), point.end(), comp2);
	for (int i = 0; i < N; i++) printf("%d ", point[i][2]);
	return 0;
}