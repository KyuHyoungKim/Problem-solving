#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int N, M;
vector<vector<vector<pair<int, int>>>> blocks = {
	{ // bar
		{{0,0},{0,1},{0,2},{0,3}},
		{{0,0},{1,0},{2,0},{3,0}}
	},
	{ // square
		{ {0,0},{0,1},{1,0},{1,1} }
	},
	{ // green block
		{{0,0},{1,0},{1,1},{2,1}},
		{{0,1},{1,1},{1,0},{2,0}},
		{{0,0},{0,1},{1,1},{1,2}},
		{{1,0},{1,1},{0,1},{0,2}}
	},
	{ // purple block
		{{1,0},{1,1},{1,2},{0,1}},
		{{0,0},{1,0},{2,0},{1,1}},
		{{0,0},{0,1},{0,2},{1,1}},
		{{0,1},{1,1},{2,1},{1,0}}

	},
	{ // orange block
		{{1,0},{1,1},{1,2},{0,2}},
		{{0,0},{1,0},{1,1},{1,2}},
		{{0,0},{0,1},{0,2},{1,2}},
		{{0,0},{0,1},{0,2},{1,0}},
		{{0,1},{1,1},{2,1},{2,0}},
		{{0,0},{1,0},{2,0},{2,1}},
		{{0,0},{0,1},{1,1},{2,1}},
		{{0,0},{0,1},{1,0},{2,0}}
	}
};
int check_blocks(vector<vector<int>>& scores) {
	int ret = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			for (int l = 0; l <blocks.size(); l++)
				for (int m = 0; m <blocks[l].size(); m++) {
					int temp = 0;
					int check = 1;
					for (int k = 0; k < 4; k++) {
						int x = j + blocks[l][m][k].second;
						int y = i + blocks[l][m][k].first;
						if (x < M && y < N) 
							temp += scores[y][x];
						else {
							check = 0;
							break;
						}
					}
					if (ret < temp && check) 
						ret = temp;
				}
		}
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	int res = 0;
	scanf("%d %d", &N, &M);
	vector<vector<int>> scores(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &scores[i][j]);
	res = check_blocks(scores);
	printf("%d\n", res);
	return 0;
}