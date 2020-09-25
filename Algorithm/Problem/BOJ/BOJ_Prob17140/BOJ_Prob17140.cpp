#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second != b.second)
		return a.second < b.second;
	else
		return a.first < b.first;
}

void R_oper(vector<vector<int>>& mat) {
	int max_idx = 0;
	for (int i = 0; i < mat.size(); i++) {
		sort(mat[i].begin(), mat[i].end(),greater<int>());
		vector<pair<int, int>> ret;
		int cnt = 1;
		ret.push_back(make_pair(mat[i][0], 1));

		for (int j = 1; j < mat[i].size(); j++) {
			if (mat[i][j] != ret[cnt - 1].first) {
				if (!mat[i][j])
					break;
				ret.push_back(make_pair(mat[i][j], 1));
				cnt++;
			}
			else
				ret[cnt - 1].second++;
		}
		sort(ret.begin(), ret.end(), comp);
		if (max_idx < cnt * 2)
			max_idx = cnt * 2;

		mat[i].clear();
		mat[i].resize(cnt * 2);

		for (int j = 0; j < cnt; j++) {
			mat[i][j*2] = ret[j].first;
			mat[i][j*2 + 1] = ret[j].second;
		}
	}
	for (int i = 0; i < mat.size(); i++)
		while (mat[i].size() < max_idx)
			mat[i].push_back(0);
}

void C_oper(vector<vector<int>>& mat) {
	int initial_size = mat.size();
	for (int j = 0; j < mat[0].size(); j++) {

		vector<int> temp;
		vector<pair<int, int>> ret;
		int cnt = 1;
		for (int i = 0; i < initial_size; i++) 
			if (mat[i][j])
				temp.push_back(mat[i][j]);

		sort(temp.begin(), temp.end());
		ret.push_back(make_pair(temp[0], 1));
		for (int i = 1 ; i < temp.size(); i++) {
			if (ret[cnt - 1].first != temp[i]) {
				ret.push_back(make_pair(temp[i], 1));
				cnt++;
			}
			else
				ret[cnt - 1].second++;
		}
	
		sort(ret.begin(), ret.end(), comp);

		while (mat.size() < cnt * 2)
			mat.push_back(vector<int>(mat[0].size(), 0));

		for (int i = 0; i < cnt; i++) {
			mat[i * 2][j] = ret[i].first;
			mat[i * 2 + 1][j] = ret[i].second;
		}
		for (int i = cnt * 2; i < mat.size(); i++)
			mat[i][j] = 0;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int r, c, k, res = 0;
	vector<vector<int>> mat(3, vector<int>(3));
	scanf("%d %d %d", &r, &c, &k);
	r--; c--;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &mat[i][j]);

	while (1) {
		if (r < mat.size() && c < mat[r].size() && k == mat[r][c])
			break;

		if (mat.size() >= mat[0].size())
			R_oper(mat);
		else
			C_oper(mat);

		res++;
		if (res > 100) {
			res = -1;
			break;
		}
	}

	printf("%d", res);
	return 0;
}