#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
//정보	전산	미래	신양	한경	진리	형남	학생
//0		1		2		3		4		5		6		7
vector<vector<int>> matrix_product(vector<vector<int>>a, vector<vector<int>>b) {
	vector<vector<int>> ret(b.size(), vector<int>(a.size()));
	for (int i = 0; i < b.size(); i++)
		for (int j = 0; j < a.size(); j++)
			for (int k = 0; k < a[0].size(); k++) {
				ret[i][j] += ((long long)a[i][k] * b[k][j]) % 1000000007;
				ret[i][j] %= 1000000007;
			}
	return ret;
}
int main() {
	int D;
	scanf("%d", &D);
	vector<vector<int>> res(8, vector<int>(8, 0));
	vector<vector<int>> graph(8, vector<int>(8, 0));
	graph[0][1] = graph[1][0] = 1;
	graph[0][2] = graph[2][0] = 1;
	graph[1][2] = graph[2][1] = 1;
	graph[1][3] = graph[3][1] = 1;
	graph[2][3] = graph[3][2] = 1;
	graph[2][4] = graph[4][2] = 1;
	graph[3][4] = graph[4][3] = 1;
	graph[3][5] = graph[5][3] = 1;
	graph[4][5] = graph[5][4] = 1;
	graph[4][6] = graph[6][4] = 1;
	graph[5][7] = graph[7][5] = 1;
	graph[6][7] = graph[7][6] = 1;
	for (int i = 0; i < 8; i++)
		res[i][i] = 1;
	for (int i = 0; (1 << i) <= D; i++) {
		if ((1 << i) & D)
			res = matrix_product(res, graph);
		graph = matrix_product(graph, graph);
	}
	printf("%d", res[0][0]);
	return 0;
}