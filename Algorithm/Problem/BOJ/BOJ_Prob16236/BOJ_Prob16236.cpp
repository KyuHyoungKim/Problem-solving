#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool comp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.first != b.first) return a.first < b.first;
	else return a.second < b.second;
}
int main() {
	freopen("input.txt", "r", stdin);
	int N, shark = 2, res = 0, cnt = 0;
	int dy[4] = { -1,0,0,1 }, dx[4] = { 0,-1,1,0 };
	scanf("%d", &N);
	vector<vector<int>> pos(N, vector<int>(N)), check(N, vector<int>(N));
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &pos[i][j]);
			if (pos[i][j] == 9) {
				q.push(make_pair(i, j));
				check[i][j] = 1;
				pos[i][j] = 0;
			}
		}
	int dist = 0;
	while (!q.empty()) {
		dist++;
		queue<pair<int, int>> Next;
		vector<pair<int, int>> finded;
		while (!q.empty()) {
			pair<int, int> now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int Y = now.first + dy[i];
				int X = now.second + dx[i];
				if (Y >= 0 && Y < N && X >= 0 && X < N && !check[Y][X])
				{
					if (pos[Y][X] == 0 || pos[Y][X] == shark) Next.push(make_pair(Y, X));
					else if (pos[Y][X] < shark) finded.push_back(make_pair(Y, X));
					check[Y][X] = 1;
				}
			}
		}
		if (!finded.empty())
		{
			vector<vector<int>> check_init(N, vector<int>(N));
			check.swap(check_init);
			sort(finded.begin(), finded.end(), comp);
			queue<pair<int, int>> temp;
			temp.push(finded[0]);
			q = temp;
			res += dist;
			dist = 0;
			pos[q.front().first][q.front().second] = 0;
			cnt++;
			if (cnt >= (shark * shark - shark) / 2 + shark - 1)	shark++;
		}
		else
			q = Next;
	}
	printf("%d\n", res);
	return 0;
}