#define _CRT_SECURE_NO_WARNINGS
#define Index_Check Y>=0 && Y < N && X >=0 && X <M
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, cnt_init = 3, res = 0, cnt_min = 65;
	int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
	scanf("%d %d", &N, &M);
	vector<vector<int>> lab_init(N, vector<int>(M));
	vector<vector<int>> lab(N, vector<int>(M));
	vector<pair<int, int>> Blanked;
	vector<pair<int, int>> Viruses;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &lab_init[i][j]);
			if (lab_init[i][j])
			{
				cnt_init++;
				if (lab_init[i][j] == 2)
					Viruses.push_back(make_pair(i, j));
			}
			else
				Blanked.push_back(make_pair(i, j));
		}

	for (int i = 0; i < Blanked.size() - 2; i++)
		for (int j = i + 1; j < Blanked.size() - 1; j++)
			for (int k = j + 1; k < Blanked.size(); k++)
			{
				lab = lab_init;
				lab[Blanked[i].first][Blanked[i].second] = 1;
				lab[Blanked[j].first][Blanked[j].second] = 1;
				lab[Blanked[k].first][Blanked[k].second] = 1;

				queue<pair<int, int>> q;
				int cnt_temp = cnt_init;
				for (int n = 0; n < Viruses.size(); n++) q.push(Viruses[n]);
				while (!q.empty()) {
					int pos_y = q.front().first;
					int pos_x = q.front().second;
					q.pop();
					for (int n = 0; n < 4; n++) {
						int Y = pos_y + dy[n];
						int X = pos_x + dx[n];
						if (Index_Check && !lab[Y][X]) {
							q.push(make_pair(Y, X));
							lab[Y][X] = 2;
							cnt_temp++;
							if (cnt_temp > cnt_min)
								break;
						}
					}
				}
				if (cnt_min > cnt_temp) {
					res = N * M - cnt_temp;
					cnt_min = cnt_temp;
				}
			}

	printf("%d\n", res);
	return 0;
}