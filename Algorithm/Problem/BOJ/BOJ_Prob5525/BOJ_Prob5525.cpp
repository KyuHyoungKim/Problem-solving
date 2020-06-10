#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
char input[1000001];
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, res = 0;
	scanf("%d %d %s", &N, &M, input);
	string str;
	vector<int> P;
	int P_cnt = 1;
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == 'I' && input[i + 1] == 'O') {
			i++;
			if (!str.empty() && str.back() == 'P') P_cnt++;
			else str += 'P';
		}
		else {
			if (!str.empty() && str.back() == 'P') {
				P.push_back(P_cnt);
				P_cnt = 1;
			}
			str += input[i];
		}
	}
	if (P_cnt > 1) P.push_back(P_cnt);
	for (int i = 0, P_cnt = 0; i < str.size(); i++) {
		if (str[i] == 'P') {
			if (P[P_cnt] > N) {
				res += P[P_cnt] - N;
				if (i < str.size() - 1 && str[i + 1] == 'I') res++;
			}
			else if (P[P_cnt] == N && i < str.size() - 1 && str[i + 1] == 'I') res++;
			P_cnt++;
		}
	}
	printf("%d\n", res);
	return 0;
}

