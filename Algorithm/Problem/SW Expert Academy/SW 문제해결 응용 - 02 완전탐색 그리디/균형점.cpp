#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double solution(vector<int> pos, vector<int> mass, int cnt)
{
	double differential = 0, position = 0, force = 0;
	differential = pos[cnt] - pos[cnt-1];
	position = (pos[cnt] + pos[cnt - 1]) / 2;

	for (int n = 0; n < 50; n++)
	{
		force = 0;
		for (int i = 0; i < cnt; i++)
			force += mass[i] / (pos[i] - position) / (pos[i] - position);
		for (int i = cnt; i < pos.size(); i++)
			force -= mass[i] / (pos[i] - position) / (pos[i] - position);
		differential /= 2;
		if (force > 0)
			position += differential;
		else if (force < 0)
			position -= differential;
		else
			break;
	}
	return position;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		scanf("%d", &N);
		vector <int> pos(N);
		vector <int> mass(N);

		for (int i = 0; i < N; i++)
			scanf("%d", &pos[i]);
		for (int i = 0; i < N; i++)
			scanf("%d", &mass[i]);

		printf("#%d\t", test_case);
		for (int i = 1; i <= N - 1; i++)
			printf("%.10lf ", solution(pos, mass, i));
		printf("\n");
	}
	return 0;
}