#include <iostream>
#include <vector>
using namespace std;
int Num_of_Node = 4;
vector<vector<int>> Graph(Num_of_Node, vector<int>());

int Solution(int pos, int visited);
vector<vector<int>> DP(Num_of_Node, vector<int>(1<<Num_of_Node, -1));

int main()
{
	int res = 100000;
	Graph[0] = { 0, 1, 2, 3 };
	Graph[1] = { 1, 0, 4, 5 };
	Graph[2] = { 2, 4, 0, 6 };
	Graph[3] = { 3, 5, 6, 0 };

	for (int i = 0; i < Num_of_Node; i++)
	{
		int temp = Solution(i, 1 << i);
		if (temp < res)
			res = temp;
	}

	printf("%d\n", res);

	return 0;
}

int Solution(int pos, int visited)
{
	if (visited == (1 << Num_of_Node) - 1)
		return 0;
	if (DP[pos][visited] != -1)
		return DP[pos][visited];
	int ret = 100000;
	int tmp = 0;
	for (int next = 0; next < Num_of_Node; next++)
	{
		if (!(1 << next & visited) && Graph[pos][next])
		{
			tmp += Graph[pos][next] + Solution(next, visited | (1 << next));
			if (tmp < ret)
				ret = tmp;
		}
	}
	DP[pos][visited] = ret;
	return ret;
}