#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	string res[2] = { "Terminates", "Loops" };
	pair<int, int> Loop;
	scanf("%d", &T);
	while (T--) {
		int M, C, I;
		int pnt_m = 0, pnt_o = 0, pnt_i = 0, cnt = 0;
		int ret = 0;
		scanf("%d %d %d", &M, &C, &I);
		vector<int> memory(M, 0);
		vector<char> orders(C);
		vector<char> inputs(I);
		vector<int> jump(C);
		vector<int> loop_check(C, -1);
		stack<pair<char, int>> bracket_check;
		getchar();
		for (int i = 0; i < C; i++) {
			scanf("%c", &orders[i]);
			if (orders[i] == '[')
				bracket_check.push(make_pair(orders[i], i));
			else if (orders[i] == ']') {
				if (bracket_check.top().first == '[') {
					jump[bracket_check.top().second] = i;
					jump[i] = bracket_check.top().second;
					bracket_check.pop();
				}
				else 
					bracket_check.push(make_pair(orders[i], i));
			}
		}
		getchar();
		for (int i = 0; i < I; i++)
			scanf("%c", &inputs[i]);
		while (1) {
			cnt++;
			if (cnt > 50000000) {
				ret = 1;
				break;
			}
			if (pnt_o >= C)
				break;
			char order = orders[pnt_o];
			if (order == '-') {
				memory[pnt_m]--;
				if (memory[pnt_m] < 0)
					memory[pnt_m] = 255;
			}
			else if (order == '+') {
				memory[pnt_m]++;
				if (memory[pnt_m] > 255)
					memory[pnt_m] = 0;
			}
			else if (order == '<') {
				pnt_m--;
				if (pnt_m < 0)
					pnt_m += M;
			}
			else if (order == '>') {
				pnt_m++;
				if (pnt_m >= M)
					pnt_m -= M;
			}
			else if (order == '[') {
				if (memory[pnt_m] == 0) {
					if (loop_check[pnt_o] < 0)
						loop_check[pnt_o] = 1;
					pnt_o = jump[pnt_o];
				}
				else
					if (loop_check[pnt_o] < 1) {
						loop_check[pnt_o]++;
						loop_check[jump[pnt_o]]++;
					}
			}
			else if (order == ']') {
				if (memory[pnt_m] != 0) {
					if (loop_check[pnt_o] < 0)
						loop_check[pnt_o] = 1;
					pnt_o = jump[pnt_o];
				}
				else
					if (loop_check[pnt_o] < 1) {
						loop_check[pnt_o]++;
						loop_check[jump[pnt_o]]++;
					}
			}
			else if (order == ',') {
				if (pnt_i < I)
					memory[pnt_m] = (int)inputs[pnt_i++];
				else
					memory[pnt_m] = 255;
			}
			pnt_o++;
		}

		for(int i = 0 ; i < C; i++)
			if (loop_check[i] == 0) {
				Loop.first = i;
				Loop.second = jump[Loop.first];
				break;
			}

		if (Loop.first > Loop.second)
			swap(Loop.first, Loop.second);
		
		printf("%s", res[ret].c_str());
		if (ret)
			printf(" %d %d", Loop.first, Loop.second);
		printf("\n");
	}
	return 0;
}