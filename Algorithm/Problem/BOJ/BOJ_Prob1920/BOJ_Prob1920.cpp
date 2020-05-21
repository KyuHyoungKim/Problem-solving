#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
int main(void)
{
	int N = 0, M = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	std::vector <int> N_Num(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &N_Num[i]);
	scanf("%d", &M);
	std::vector <std::pair<int, int>> M_Num(M);
	std::vector <int> result(M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &M_Num[i].first);
		M_Num[i].second = i;
	}

	sort(N_Num.begin(), N_Num.end());
	sort(M_Num.begin(), M_Num.end());

	int i = 0;
	int j = 0;
	for (; i < M && j<N; )
	{
		if (M_Num[i].first < N_Num[j]) {
			result[M_Num[i].second] = 0;
			i++;
		}
		else if (M_Num[i].first == N_Num[j]) {
			result[M_Num[i].second] = 1;
			i++;
		}
		else {
			j++;
		}
	}
	for (int i = 0; i < M; i++)
		printf("%d\n", result[i]);
	return 0;
}