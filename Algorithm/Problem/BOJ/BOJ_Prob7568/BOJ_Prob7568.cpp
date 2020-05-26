#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int N = 0, x = 0, y = 0, cnt = 1;
	scanf("%d", &N);
	vector<vector<int>> people(N, vector<int>(3)); // ¸ö¹«°Ô,Å°, µ¢Ä¡¼øÀ§-1
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		people[i].at(0) = x;
		people[i].at(1) = y;
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (people[i].at(0) < people[j].at(0) && people[i].at(1) < people[j].at(1)) people[i].at(2)++;
		}

	for (int i = 0; i < N; i++) printf("%d ", people[i].at(2) + 1);
	return 0;
}