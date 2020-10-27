#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int mod;

inline vector<int> get_pi(string& str) {
	int n = str.size();
	vector<int> pi(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && str[i] != str[j])
			j = pi[j - 1];
		if (str[i] == str[j])
			pi[i] = ++j;
	}
	return pi;
}

inline int KMP(vector<int>& str1, vector<int>& str2, vector<int>& pi, int st) {
	int n = str1.size(), m = str2.size();
	int ret = 0;
	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && str1[i] != (str2[j] + st) % mod)
			j = pi[j - 1];

		if (str1[i] == (str2[j] + st) % mod) {
			if (j == m - 1) {
				ret++;
				j = pi[j];
			}
			else
				j++;
		}
	}

	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);

	int T; cin >> T;

	while (T--) {
		string A, W, S;
		vector<int> res;
		vector<int> converted_W, converted_S;
		map<char, int> char2idx;
		cin >> A >> W >> S;
		mod = A.size();
		auto pi = get_pi(W);
		converted_W.resize(W.size());
		converted_S.resize(S.size());

		for (int i = 0; i < mod; i++)
			char2idx.insert(make_pair(A[i], i));
		for (int i = 0; i < W.size(); i++)
			converted_W[i] = char2idx[W[i]];
		for (int i = 0; i < S.size(); i++)
			converted_S[i] = char2idx[S[i]];

		for (int i = 0; i < mod; i++) 
			if (KMP(converted_S, converted_W, pi, i) == 1)
				res.push_back(i);

		if (res.size() == 0)
			printf("no solution\n");
		else if (res.size() == 1)
			printf("unique: %d\n", res[0]);
		else {
			printf("ambiguous: ");
			for (int i = 0; i < res.size(); i++)
				printf("%d ", res[i]);
			printf("\n");
		}
	}
	return 0;
}