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
vector<vector<int>> path = {
	{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38},
	{0,13,16,19},
	{0,22,24},
	{0,28,27,26},
	{25,30,35,40}
};
vector<unit> units(4);
vector<vector<bool>> check(5);
vector<bool> finished(4, false);

int play_game(int cnt);

int main() {
	freopen("input.txt", "r", stdin);
	int res = 0;
	for (int i = 0; i < 10; i++)
		scanf("%d", &inputs[i]);
	for (int i = 0; i < path.size(); i++)
		check[i].resize(path[i].size(), false);

	res = play_game(0);
	printf("%d", res);

	return 0;
}

int play_game(int cnt) {
	if (cnt >= 10)
		return 0;

	int a, ret = 0;

	for (int i = 0; i < 4; i++) {
		if (finished[i])
			continue;

		a = 0;
		int path_origin;
		int pos_origin;
		int path_new = path_origin = units[i].path;
		int pos_new = pos_origin = units[i].pos;
		bool flag_finished = false;
		if (path_new == 0 && pos_new % 5 == 0) {
			path_new = pos_new / 5;
			pos_new = 0;
		}
		pos_new += inputs[cnt];

		if (path_new < 4 && pos_new >= path[path_new].size()) {
			pos_new -= path[path_new].size();
			if (!path_new)
				pos_new += 3;
			path_new = 4;
		}

		if (pos_new >= path[path_new].size()) {
			check[path_origin][pos_origin] = false;
			finished[i] = true;
			flag_finished = true;
		}
		else if (check[path_new][pos_new])
			continue;
		else {
			check[path_origin][pos_origin] = false;
			check[path_new][pos_new] = true;

			units[i].path = path_new;
			units[i].pos = pos_new;
			a += path[path_new][pos_new];
		}

		a += play_game(cnt + 1);
		check[path_origin][pos_origin] = true;
		if (!flag_finished)
			check[path_new][pos_new] = false;
		units[i].path = path_origin;
		units[i].pos = pos_origin;
		finished[i] = false;
		if (ret < a)
			ret = a;
	}

	return ret;
}