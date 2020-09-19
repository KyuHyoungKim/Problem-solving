#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, L, res = 0;
	scanf("%d %d", &N, &L);
	vector<vector<int>> Map(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &Map[i][j]);

	for (int i = 0; i < N; i++) {
		int height = Map[i][0];
		int length = 1;
		bool flag = true;
		int j = 1;
		for (; j < N; j++) {
			int h = Map[i][j];

			if (flag == false)
				if (length >= L) {
					length -= L;
					flag = true;
				}

			if (height == h)
				length++;
			else if (abs(height - h) > 1)
				break;
			else if (!flag && length < L)
				break;
			else if (height < h) {
				if (length < L)
					break;
				height = h;
				length = 1;
			}
			else {
				height = h;
				length = 1;
				flag = false;
			}
		}
		if (j == N && (!(!flag && length < L)))
			res++;
	}
	

	for (int i = 0; i < N; i++) {
		int height = Map[0][i];
		int length = 1;
		bool flag = true;
		int j = 1;
		for (; j < N; j++) {
			int h = Map[j][i];

			if (flag == false) 
				if (length >= L) {
					length -= L;
					flag = true;
				}

			if (height == h)
				length++;
			else if (abs(height - h) > 1)
				break;
			else if (!flag && length < L)
				break;
			else if (height < h) {
				if (length < L)
					break;
				height = h;
				length = 1;
			}
			else {
				height = h;
				length = 1;
				flag = false;
			}
		}
		if (j == N && (!(!flag && length < L)))
			res++;
	}


	printf("%d", res);
	return 0;
}