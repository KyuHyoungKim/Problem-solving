#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> A[8]; // Graph
bool checked[8];

void BFS(int start)
{
	queue<int> Q;
	Q.push(start);
	for (; !Q.empty();)
	{
		int temp = Q.front();
		Q.pop();
		checked[temp] = true;
		printf("%d ", temp);
		for (int i = 0;i<A[temp].size();i++)
		{
			if (!checked[A[temp][i]])
			{
				Q.push(A[temp][i]);
				checked[A[temp][i]] = true;
			}
		}
	}
}

int main(void)
{
	A[1].push_back(2);
	A[2].push_back(1);

	A[1].push_back(3);
	A[3].push_back(1);

	A[2].push_back(3);
	A[3].push_back(2);

	A[2].push_back(4);
	A[4].push_back(2);

	A[2].push_back(5);
	A[5].push_back(2);

	A[4].push_back(5);
	A[5].push_back(4);

	A[3].push_back(6);
	A[6].push_back(3);

	A[3].push_back(7);
	A[7].push_back(3);

	A[6].push_back(7);
	A[7].push_back(6);

	BFS(1);
	return 0;
}
/*
		  1
		/	\
	2----------	3
  /	   \	  /	  \
4------ 5	6-------7
*/
