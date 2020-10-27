#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N, K, res = 0;
vector<string> strs;
string str;


void solution(int cnt, int check);
inline vector<int> get_pi();
inline void KMP();

int main() {
	freopen("input.txt", "r", stdin);

	cin >> N;
	getchar();
	strs.resize(N);
	for (int i = 0; i < N; i++)
		getline(cin, strs[i]);
	cin >> K;
	solution(0, 0);

	printf("%d", res);
	return 0;
}

void solution(int cnt, int check) {
	if (cnt >= N) {
		KMP();
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (check & 1 << i)
			continue;
		str += strs[i];
		solution(cnt + 1, check | 1 << i);
		for (int j = 0; j < strs[i].size(); j++)
			str.pop_back();
	}
}

inline vector<int> get_pi() {
	int n = (int)str.size();
	vector<int> ret(n);

	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && str[i] != str[j])
			j = ret[j - 1];
		if (str[i] == str[j])
			ret[i] = ++j;
	}
	return ret;
}

inline void KMP() {
	int cnt = -1, n = (int)str.size();
	string word = str + str;
	auto pi = get_pi();
	for (int i = 0, j = 0; i < 2 * n; i++) {
		while (j > 0 && word[i] != str[j])
			j = pi[j - 1];

		if (word[i] == str[j]) {
			if (j == n - 1) {
				cnt++;
				j = pi[j];
			}
			else
				j++;
		}
	}
	if (cnt == K)
		res++;

	return;
}