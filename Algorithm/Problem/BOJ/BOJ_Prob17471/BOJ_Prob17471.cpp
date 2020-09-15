#define _CRT_SECURE_NO_WARNINGS
#define INF 1234567891
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> graph;
vector<int> value;
vector<int> teamA;
vector<int> teamB;
vector<int> DP;
vector<int> parent;

int find_parent(int idx);
void unionize(int idx1, int idx2);
int solution(int checked);
int organize_team(int idx, int checked);

int main() {
	freopen("input.txt", "r", stdin);
	int res;
	scanf("%d", &N);
	value.resize(N);
	graph.resize(N);
	DP.resize(1 << N);
	parent.resize(N);
	DP[0] = DP[(1 << N) - 1] = INF;

	for (int i = 0; i < N; i++) 
		scanf("%d", &value[i]);
	
	for (int i = 0; i < N; i++) {
		int M, tail;
		scanf("%d", &M);
		for (int j = 0; j < M; j++) {
			scanf("%d", &tail);
			graph[i].push_back(tail - 1);
		}
	}
	res = organize_team(0, 0);
	if (res == INF)
		res = -1;
	printf("%d", res);
	return 0;
}

int find_parent(int idx) {
	if (parent[idx] == idx)
		return idx;
	else
		return parent[idx] = find_parent(parent[idx]);
}

void unionize(int idx1, int idx2) {
	idx1 = find_parent(idx1);
	idx2 = find_parent(idx2);
	if (idx1 > idx2) swap(idx1, idx2);
	parent[idx2] = idx1;
}

int solution(int checked) {
	int teamA_value = 0, teamB_value = 0, ret = 0;

	for (int i = 0; i < N; i++)
		parent[i] = i;
	if (teamA.size() == 1)
		teamA_value = value[teamA[0]];
	else
		for (int i = 0; i < teamA.size(); i++) {
			teamA_value += value[teamA[i]];
			for (int j = 0; j < graph[teamA[i]].size(); j++)
				if (checked & (1 << graph[teamA[i]][j]))
					unionize(teamA[i], graph[teamA[i]][j]);
		}
	for (int j = 1; j < teamA.size(); j++)
		if (find_parent(teamA[j]) != find_parent(teamA[j - 1])) {
			ret = INF;
			break;
		}

	if (ret != INF) {
		for (int i = 0; i < N; i++)
			parent[i] = i;
		if (teamB.size() == 1)
			teamB_value = value[teamB[0]];
		else
			for (int i = 0; i < teamB.size(); i++) {
				teamB_value += value[teamB[i]];
				for (int j = 0; j < graph[teamB[i]].size(); j++)
					if (!(checked & (1 << graph[teamB[i]][j])))
						unionize(teamB[i], graph[teamB[i]][j]);
			}
		for (int j = 1; j < teamB.size(); j++)
			if (find_parent(teamB[j]) != find_parent(teamB[j - 1])) {
				ret = INF;
				break;
			}
	}

	if (ret != INF)
		ret = abs(teamA_value - teamB_value);

	DP[checked] = DP[(1 << N) - 1 - checked] = ret;
	return ret;
}

int organize_team(int idx, int checked) {
	if (idx == N)
		return solution(checked);
	int a1, a2, ret;
	teamA.push_back(idx);
	a1 = organize_team(idx + 1, checked | 1 << idx);
	teamA.pop_back();
	teamB.push_back(idx);
	a2 = organize_team(idx + 1, checked);
	teamB.pop_back();
	ret = (a1 < a2) ? a1 : a2;
	return ret;
}