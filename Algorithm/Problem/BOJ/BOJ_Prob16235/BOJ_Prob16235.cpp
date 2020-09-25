#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dx[8] = { -1,0,1,-1,1,-1,0,1 };

struct wood_info {
	int y;
	int x;
	int old;
};

bool comp(const wood_info& a, const wood_info& b) {
	return a.old < b.old;
}

wood_info make_wood(int y, int x, int old);
void spring(vector<vector<int>>& farm, vector<wood_info>& woods, vector<wood_info>& dead, vector<wood_info>& propagation, vector<wood_info>& young_woods);
void summer(vector<wood_info>& dead_woods, vector<vector<int>>& farm);
void autumn(vector<wood_info>& propagation, int N, vector<wood_info>& young_woods);
void winter(vector<vector<int>>& farm, vector<vector<int>>& robot, int N);

int main() {
	freopen("input.txt", "r", stdin);
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	vector<vector<int>> farm(N + 1, vector<int>(N + 1, 5));
	vector<vector<int>> robot(N + 1, vector<int>(N + 1));
	vector<wood_info> woods(M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &robot[i][j]);

	for (int i = 0; i < M; i++)
		scanf("%d %d %d", &woods[i].y, &woods[i].x, &woods[i].old);
	sort(woods.begin(), woods.end(), comp);

	vector<wood_info> young_woods, dead_woods, propagation;
	while (K--) {
		spring(farm, woods, dead_woods, propagation, young_woods);
		summer(dead_woods, farm);
		autumn(propagation, N, young_woods);
		winter(farm, robot, N);
	}

	printf("%d", woods.size() + young_woods.size());
	return 0;
}

wood_info make_wood(int y, int x, int old) {
	wood_info ret;
	ret.y = y;
	ret.x = x;
	ret.old = old;
	return ret;
}

void spring(vector<vector<int>>& farm, vector<wood_info>& woods, vector<wood_info>& dead_woods, vector<wood_info>& propagation, vector<wood_info>& young_woods) {
	dead_woods.clear(), propagation.clear();
	vector<wood_info> new_woods;
	for (int i = 0; i < young_woods.size(); i++) {
		if (farm[young_woods[i].y][young_woods[i].x]) {
			farm[young_woods[i].y][young_woods[i].x] -= 1;
			young_woods[i].old++;
			new_woods.push_back(young_woods[i]);
		}
		else
			dead_woods.push_back(young_woods[i]);
	}
	young_woods.clear();
	for (int i = 0; i < woods.size(); i++) {
		if (farm[woods[i].y][woods[i].x] >= woods[i].old) {
			farm[woods[i].y][woods[i].x] -= woods[i].old;
			woods[i].old++;
			new_woods.push_back(woods[i]);
			if (!(woods[i].old % 5))
				propagation.push_back(woods[i]);
		}
		else
			dead_woods.push_back(woods[i]);
	}
	woods.swap(new_woods);
}

void summer(vector<wood_info>& dead_woods, vector<vector<int>>& farm) {
	for (int i = 0; i < dead_woods.size(); i++)
		farm[dead_woods[i].y][dead_woods[i].x] += dead_woods[i].old / 2;
}

void autumn(vector<wood_info>& propagation, int N, vector<wood_info>& young_woods) {
	for (int i = 0; i < propagation.size(); i++) {
		int Y = propagation[i].y;
		int X = propagation[i].x;
		for (int j = 0; j < 8; j++) {
			int y = Y + dy[j];
			int x = X + dx[j];
			if (y < 1 || y > N || x < 1 || x > N)
				continue;
			young_woods.push_back(make_wood(y, x, 1));
		}
	}
}

void winter(vector<vector<int>>& farm, vector<vector<int>>& robot, int N) {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			farm[i][j] += robot[i][j];
}