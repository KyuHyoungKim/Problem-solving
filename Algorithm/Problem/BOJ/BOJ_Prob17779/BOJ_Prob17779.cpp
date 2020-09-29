#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, res = 1234567891;
	scanf("%d", &N);
	vector<vector<int>> popul(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &popul[i][j]);

	for (int x = 2; x <= N - 1; x++)
		for (int y = 2; y <= N - 1; y++)
			for (int L1 = 1; L1 + x <= N && y - L1 > 0; L1++)
				for (int L2 = 1; x + L1 + L2 <= N && y + L2 <= N; L2++) {
					vector<vector<int>>sector(N + 1, vector<int>(N + 1));
					vector<int> boundary(4);
					vector<int> popul_sum(6);
					int ret;

					boundary[0] = y - L1;
					boundary[1] = y;
					boundary[2] = y + L2 - L1;
					boundary[3] = y + L2;
					for (int i = 1; i <= N; i++)
						for (int j = 1; j <= N; j++)
						{
							if (i < boundary[0]) {
								if (j <= x + L1) {
									sector[i][j] = 1;
								}
								else
									sector[i][j] = 2;
							}
							else if (i < boundary[1]) {
								if (j < -i + x + y)
									sector[i][j] = 1;
								else {
									if (i <= boundary[2]) {
										if (j <= i + 2 * L1 + x - y)
											sector[i][j] = 5;
										else
											sector[i][j] = 2;
									}
									else {
										if (j <= -i + 2 * L2 + x + y)
											sector[i][j] = 5;
										else
											sector[i][j] = 4;
									}
								}
							}
							else if (i <= boundary[3]) {
								if (j < i + x - y)
									sector[i][j] = 3;
								else {
									if (i <= boundary[2]) {
										if (j <= i + 2 * L1 + x - y)
											sector[i][j] = 5;
										else
											sector[i][j] = 2;
									}
									else {
										if (j <= -i + 2 * L2 + x + y)
											sector[i][j] = 5;
										else
											sector[i][j] = 4;
									}
								}
							}
							else {
								if (j < x + L2)
									sector[i][j] = 3;
								else
									sector[i][j] = 4;
							}
						}

					for (int i = 1; i <= N; i++)
						for (int j = 1; j <= N; j++)
							popul_sum[sector[i][j]] += popul[i][j];
					sort(popul_sum.begin(), popul_sum.end());
					ret = popul_sum[5] - popul_sum[1];
					if (res > ret)
						res = ret;
				}


	printf("%d", res);
	return 0;
}