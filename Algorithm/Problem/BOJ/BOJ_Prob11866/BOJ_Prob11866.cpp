#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	int N = 0, K = 0, index = -1;
	vector<int> people;
	scanf("%d %d", &N, &K);
	printf("<");
	for (int i = 1; i <= N; i++) people.push_back(i);
	for (int i = 0; i < N; i++)
	{
		for (int i = 0; i < K; i++)
		{
			index = (index + 1) % N;
			if (!people[index])
				i--;
		}
		printf("%d", people[index]);
		if (i != N - 1) printf(", ");
		else printf(">");
		people[index] = 0;
	}
	return 0;
}