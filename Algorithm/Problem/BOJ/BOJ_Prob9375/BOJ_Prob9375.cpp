#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
#include <string>
using namespace std;
int sol(map<string, int> ::iterator iter, int now, int cnt, int max_index, int check) {
	int ret = 0, a1, a2;
	if (now == max_index) {
		if (check) return cnt;
		else return 0;
	}
	a1 = sol(++iter, now + 1, cnt, max_index, check);
	iter--;
	cnt *= (*iter).second;
	a2 = sol(++iter, now + 1, cnt, max_index, check + 1);
	ret = a1 + a2;
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	int T, N, res;
	char clothes_inp[2][21];
	scanf("%d", &T);
	while (T--) {
		map<string, int> clothes;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%s %s", clothes_inp[0], clothes_inp[1]);
			string temp = clothes_inp[1];
			clothes[temp]++;
		}
		res = sol(clothes.begin(), 0, 1, clothes.size(), 0);
		printf("%d\n", res);
	}
	return 0;
}