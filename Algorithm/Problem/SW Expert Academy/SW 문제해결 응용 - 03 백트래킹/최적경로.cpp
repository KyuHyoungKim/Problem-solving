#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int ret;
int Home_pos[2];
int Work_pos[2];
vector<int> x_pos;
vector<int> y_pos;

int solution(int cur_pos, int N, int checked, int result);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N = 0;
		scanf("%d", &N);
		x_pos.clear();
		y_pos.clear();
		int temp[2];
		scanf("%d %d %d %d", &Work_pos[0], &Work_pos[1], &Home_pos[0], &Home_pos[1]);
		ret = (1 << 31) - 1;
		for (int i = 0; i < N; i++)
		{
			scanf("%d %d", &temp[0], &temp[1]);
			x_pos.push_back(temp[0]); y_pos.push_back(temp[1]);
		}
		solution(0, N, 0, 0);
		printf("#%d %d\n", test_case, ret);

	}
	return 0;
}

int solution(int cur_pos, int N, int checked, int result)
{
	if (checked == ((1 << N) - 1))
	{
		result += abs(x_pos[cur_pos] - Home_pos[0]) + abs(y_pos[cur_pos] - Home_pos[1]);
		if (result < ret)
			ret = result;
		return 0;
	}
	if (result > ret)
		return 0;

	for (int i = 0; i < x_pos.size(); i++)
	{
		if (checked == 0)
			solution(i, N, checked | (1 << i), result + abs(Work_pos[0] - x_pos[i]) + abs(Work_pos[1] - y_pos[i]));
		else if (!(checked & 1 << i))
			solution(i, N, checked | (1 << i), result + abs(x_pos[cur_pos] - x_pos[i]) + abs(y_pos[cur_pos] - y_pos[i]));
	}
	// return result;
}