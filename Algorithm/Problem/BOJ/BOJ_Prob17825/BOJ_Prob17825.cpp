#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

class unit {
public:
	int path = 0;
	int pos = 0;
};

vector<int> inputs(10); 
vector<vector<int>> path(5);

void init(vector<vector<int>>& path, vector<vector<bool>>& check);
int play_game(vector<unit> units, int cnt, vector<bool> finished, vector<vector<bool>> check);

int main() {
	freopen("input.txt", "r", stdin);
	int res = 0;
	vector<unit> units(4);
	vector<vector<bool>> check(5);
	vector<bool> finished(4, false);
	for (int i = 0; i < 10; i++)
		scanf("%d", &inputs[i]);
	init(path, check);

	res = play_game(units, 0, finished, check);
	printf("%d", res);
	
	return 0;
}

void init(vector<vector<int>>& path, vector<vector<bool>>& check) {
	path[0].resize(22);
	path[1].resize(5);
	path[2].resize(4);
	path[3].resize(5);
	path[4].resize(5);
	for (int i = 1; i <= 20; i++)
		path[0][i] = 2 * i;

	path[1][1] = 13;
	path[1][2] = 16;
	path[1][3] = 19;

	path[2][1] = 22;
	path[2][2] = 24;

	path[3][1] = 28;
	path[3][2] = 27;
	path[3][3] = 26;

	path[4][0] = 25;
	path[4][1] = 30;
	path[4][2] = 35;
	path[4][3] = 40;

	for (int i = 0; i < path.size(); i++)
		check[i].resize(path[i].size(), false);
}

int play_game(vector<unit> units, int cnt, vector<bool> finished, vector<vector<bool>> check) {
	if (cnt >= 10)
		return 0;
	
	int a, ret = 0;

	for (int i = 0; i < 4; i++) {
		if (finished[i])
			continue;

		a = 0;
		vector<unit> units_new = units;
		vector<bool> finished_new = finished;
		vector<vector<bool>> check_new = check;
		int path_origin;
		int pos_origin;
		int path_new = path_origin = units_new[i].path;
		int pos_new = pos_origin = units_new[i].pos;

		if (path_new == 0 && pos_new % 5 == 0 && pos_new < 20) {
			path_new = pos_new / 5;
			pos_new = 0;
		}
		pos_new += inputs[cnt];

		if (path_new == 0 && pos_new >= 20) {
			path_new = 4;
			pos_new -= 17;
		}
		else if (path_new > 0 && path_new < 4 && pos_new >= path[path_new].size() - 1) {
			pos_new -= (path[path_new].size() - 1);
			path_new = 4;
		}

		if (pos_new >= path[path_new].size() - 1) {
			check_new[path_origin][pos_origin] = false;
			finished_new[i] = true;
		}
		else if (check[path_new][pos_new])
			continue;
		else {
			check_new[path_origin][pos_origin] = false;
			check_new[path_new][pos_new] = true;

			units_new[i].path = path_new;
			units_new[i].pos = pos_new;
			a += path[path_new][pos_new];
		}

		a += play_game(units_new, cnt + 1, finished_new, check_new);
		if (ret < a)
			ret = a;
	}

	return ret;
}