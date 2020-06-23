#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, forgot_list = 0;
	char input[1001];
	scanf("%d %d", &N, &M);
	vector<int> words(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", input);
		for (int j = 0; input[j] != '\0'; j++)
			words[i] |= 1 << (input[j] - 'a');
	}
	while (M--)
	{
		int order, cnt = N;
		char cha;
		scanf("%d %c", &order, &cha);
		if (order == 1) forgot_list |= 1 << (cha - 'a');
		else forgot_list &= ~(1 << (cha - 'a'));

		for (int i = 0; i < N; i++)
			if (words[i] & forgot_list) cnt--;

		printf("%d\n", cnt);
	}
	return 0;
}