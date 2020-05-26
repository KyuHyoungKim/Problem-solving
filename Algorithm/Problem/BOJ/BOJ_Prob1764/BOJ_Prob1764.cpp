#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	char input[21];
	string name;
	vector<string> a(N), b(M), c;
	for (int i = 0; i < N; i++) {
		scanf("%s", input);
		a[i] = input;
	}
	for (int i = 0; i < M; i++) {
		scanf("%s", input);
		b[i] = input;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int i = 0, j = 0;

	for (; i < a.size() && j < b.size();) {
		if (a[i] == b[j]) {
			c.push_back(a[i]);
			i++; j++;
		}
		else if (a[i] < b[j]) i++;
		else j++;
	}
	printf("%d\n", c.size());
	for (int i = 0; i < c.size(); i++) cout << c[i] << '\n';
	return 0;
}