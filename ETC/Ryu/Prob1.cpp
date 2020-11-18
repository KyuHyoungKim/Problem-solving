#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
int MIN = 1234567891, MAX = 0;

void solution(int num, int cnt) {
	string num_str = to_string(num);
	int len = num_str.size();
	for (int i = 0; i < len; i++) {
		int unit = num_str[i] - '0';
		if (unit % 2)
			cnt++;
	}
	if (len >= 3) 
		for (int i = 0; i < len - 2; i++)
			for (int j = i + 1; j < len - 1; j++) {
				int split_1 = stoi(num_str.substr(0, i + 1));
				int split_2 = stoi(num_str.substr(i + 1, j - i));
				int split_3 = stoi(num_str.substr(j + 1));

				solution(split_1 + split_2 + split_3, cnt);
			}
	else if (len == 2)
		for (int i = 0; i < len - 1; i++) {
			int split_1 = stoi(num_str.substr(0, i + 1));
			int split_2 = stoi(num_str.substr(i + 1));
			solution(split_1 + split_2, cnt);
		}
	else {
		if (MAX < cnt)
			MAX = cnt;
		if (MIN > cnt)
			MIN = cnt;
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	int num;
	cin >> num;
	solution(num,0);
	printf("%d %d",MIN, MAX);

	return 0;
}