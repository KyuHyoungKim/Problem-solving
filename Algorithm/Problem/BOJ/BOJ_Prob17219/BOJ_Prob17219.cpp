#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int N, M;
	char site[21], pw[21];

	scanf("%d %d", &N, &M);
	map<string, string> passwords;
	while (N--) {
		scanf("%s %s", site, pw);
		string a = site, b = pw;
		passwords.insert(make_pair(a, b));
	}
	while (M--) {
		scanf("%s", site);
		string s = site;
		cout << passwords[s] << '\n';
	}
	return 0;
}