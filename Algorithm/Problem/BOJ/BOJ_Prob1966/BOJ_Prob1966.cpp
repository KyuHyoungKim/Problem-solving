#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int T, N, M;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		int temp, cnt = 0;
		vector<int> impor;
		queue<pair<int,int>> doc; // importance, document
		pair<int, int> target;
		pair<int, int> print;
		for (int i = 0; i < N; i++) {
			scanf("%d", &temp);
			doc.push(make_pair(temp, i));
			if (i == M) target = { temp, i };
			impor.push_back(temp);
		}
		sort(impor.begin(), impor.end(),greater<int>());
		while (print != target) {
			if (doc.front().first == impor[cnt])
			{
				print = doc.front();
				doc.pop();
				cnt++;
			}
			else {
				doc.push(doc.front());
				doc.pop();
			}
		}

		printf("%d\n", cnt);
	}
	return 0;
}