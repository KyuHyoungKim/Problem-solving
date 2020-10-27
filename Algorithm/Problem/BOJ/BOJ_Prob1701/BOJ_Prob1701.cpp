#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string str;
int N, res = 0;

int main() {
	freopen("input.txt", "r", stdin);

	getline(cin, str);
	N = str.size();
	for (int n = 0; n < N - res; n++) {
		vector<int> cnt(N - n);
		for (int i = 1, j = 0; i < N - n; i++) {
			while (j> 0 && str[i + n] != str[j + n])
				j = cnt[j - 1];

			if (str[i + n] == str[j + n]) 
				cnt[i] = ++j;

			if (j > res)
				res = j;
		}
	}
	cout << res;
	return 0;
}