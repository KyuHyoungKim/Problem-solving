#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> find_pi(string P) {
	vector<int> pi(P.size());
	for (int i = 1, j = 0; i < P.size(); i++) {
		while (j > 0 && P[i] != P[j])
			j = pi[j - 1];
		if (P[i] == P[j])
			pi[i] = ++j;
	}
	return pi;
}

bool KMP(string S, string P) {
	vector<int> pi = find_pi(P);
	for (int i = 0, j = 0; i < S.size(); i++) {
		while (j > 0 && S[i] != P[j])
			j = pi[j - 1];
		if (S[i] == P[j]) {
			j++;
			if (j == P.size())
				return true;
		}
	}
	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	string S, P;
	getline(cin, S);
	getline(cin, P);
	printf("%d", KMP(S, P));
	return 0;
}