#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N = 0, M = 0;
	scanf("%d %d", &N, &M);
	vector<string> PokeList(N + 1);
	char input[21];
	string str_temp;
	map<string, int> PokeList_map;
	for (int i = 1; i <= N; i++) {
		scanf("%s", input);
		PokeList.at(i) = input;
		PokeList_map.insert(make_pair(PokeList.at(i), i));
	}
	while (M--) {
		scanf("%s", input); str_temp = input;
		if (input[0] >= '0' && input[0] <= '9') printf("%s\n", PokeList[stoi(input)].c_str());
		else printf("%d\n", PokeList_map[str_temp]);
	}
	return 0;
}