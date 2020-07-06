#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> find_pi_vector(string str) {
	vector<int> pi(str.size());
	int j = 0;
	for (int i = 1; i < str.size(); i++) {
		while (j > 0 && str[i] != str[j])
			j = pi[j - 1];
		if (str[i] == str[j])
			pi[i] = ++j;
	}
	return pi;
}

vector<int> KMP(string str1, string str2) {
	vector<int> pi_str2 = find_pi_vector(str2);
	vector<int> ret;
	for (int i = 0, j = 0; i < str1.size(); i++) {
		while (j > 0 && str1[i] != str2[j])
			j = pi_str2[j - 1];
		if (str1[i] == str2[j]) {
			j++;
			if (j == str2.size()) {
				ret.push_back(i - str2.size() + 2);
				j = pi_str2[j - 1];
			}
		}
	}
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	vector<int> res = KMP(str1, str2);
	
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d ", res[i]);
	return 0;
}