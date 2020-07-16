#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
vector<int> required_time;
vector<int> result_time;
vector<vector<int>> priority;
int investigate_time(int num) {
	if (result_time[num]) 
		return result_time[num];
	
	int ret = 0;
	for (int i = 0; i < priority[num].size(); i++) {
		int a = investigate_time(priority[num][i]);
		if (ret < a) ret = a;
	}
	ret += required_time[num];
	result_time[num] = ret;
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	required_time.resize(N);
	result_time.resize(N);
	priority.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &required_time[i]);
		while (1) {
			int node;
			scanf("%d", &node);
			if (node < 0) break;
			priority[i].push_back(node - 1);
		}
	}
	for (int i = 0; i < N; i++) {
		if (result_time[i]) continue;
		result_time[i] = investigate_time(i);
	}
	for (int i = 0; i < N; i++)
		printf("%d\n", result_time[i]);
	return 0;
}