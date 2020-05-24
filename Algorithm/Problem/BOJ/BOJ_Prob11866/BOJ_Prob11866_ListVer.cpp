#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <list>
int main()
{
	freopen("input.txt", "r", stdin);
	int N = 0, K = 0;
	std::list<int> people;
	std::list<int>::iterator iter;
	scanf("%d %d", &N, &K);
	printf("<");
	for (int i = 1; i <= N; i++) people.push_back(i);
	iter = people.begin();
	while (!people.empty()) {
		for (int i = 0; i < K - 1; i++) {
			++iter;
			if (iter == people.end()) iter = people.begin();
		}
		printf("%d", *iter);
		people.erase(iter++);
		if (iter == people.end()) iter = people.begin();
		if (people.size() > 0) printf(", ");
	}
	printf(">");
	return 0;
}