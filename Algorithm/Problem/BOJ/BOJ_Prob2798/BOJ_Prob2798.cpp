#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0, M = 0, result = 0;
	scanf("%d %d", &N, &M);
	vector<int> cards(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &cards[i]);
	sort(cards.begin(), cards.end(), less<int>());
	for(int i = 0 ; i < N; i++)
		for(int j = i + 1; j < N; j++)
			for (int k = j + 1; k < N; k++)
			{
				int temp = cards[i] + cards[j] + cards[k];
				if (temp > M)
					break;
				if (temp > result)
					result = temp;
			}

	printf("%d\n", result);
	return 0;
}