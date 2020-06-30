#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, K, cnt = 0;
	scanf("%d %d %d", &N, &M, &K);
	long long x = 1;
	long long truth = 0; // 알고잇는 사람들
	long long party_check = 0; // 파티 체크
	long long parties[50] = { 0 }; // 파티정보

	for (int i = 0; i < K; i++) {
		int people;
		scanf("%d", &people);
		truth |= x << people;
	}

	for (int i = 0; i < M; i++)
	{
		int num_of_people, people;
		scanf("%d", &num_of_people);
		for (int j = 0; j < num_of_people; j++)
		{
			scanf("%d", &people);
			parties[i] |= x << people;
		}
	}

	for (int i = 0; i < M; i++)
	{
		if (truth & parties[i] && !(party_check & x << i)) {
			party_check |= x << i;
			truth |= parties[i];
			cnt++;
		}
		for (int j = 0; j < M; j++)
		{
			if (truth & parties[j] && !(party_check & x << j)) {
				party_check |= x << j;
				truth |= parties[j];
				cnt++;
			}
		}
	}

	printf("%d\n", M - cnt);
	return 0;
}