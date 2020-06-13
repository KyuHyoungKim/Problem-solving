#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
#include <string>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int T;
	char clothes_inp[2][21];
	scanf("%d", &T);
	while (T--) {
		int N, res = 1;
		map<string, int> clothes;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%s %s", clothes_inp[0], clothes_inp[1]);
			string temp = clothes_inp[1];
			clothes[temp]++;
		}
		for (map<string, int> ::iterator iter = clothes.begin(); iter != clothes.end(); iter++)
			res *= (iter->second + 1);
		printf("%d\n", res - 1);
	}
	return 0;
}