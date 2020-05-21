#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N = 0;
	scanf("%d", &N);
	vector<int> Num(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &Num[i]);
	sort(Num.begin(), Num.end());
	for (int i = 0; i < N; i++)
		printf("%d\n", Num[i]);
	return 0;
}