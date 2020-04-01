#include <iostream>
#include <vector>

using namespace std;

vector<int> A[8];
bool checked[8];

void DFS_Recursion(int start)
{
	printf("%d\n", start);
	checked[start] = true;
	for (int i = 0 ;i<A[start].size();i++)
	{
		if (!checked[A[start][i]])
			DFS_Recursion(A[start][i]);
	}
}

int main()
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

	DFS_Recursion(1);
	return 0;
}

/*
				1
			/		\
		2---------------3
	/		\		/		\
4--------------5  6-----------7
*/