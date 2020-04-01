#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> A[8];
bool checked[8];

void DFS(int start)
{
	stack<int> S;
	S.push(start);
	int a = S.top();
	printf("%d\n", a);
	checked[start] = true;

	for (; !S.empty();)
	{
		for (int i = 0; i < A[a].size(); i++)
		{
			if (!checked[A[a][i]])
			{
				S.push(A[a][i]);
				a = S.top();
				printf("%d\n", a);
				checked[a] = true;
				break;
			}
			if (i == A[a].size() - 1)
			{
				S.pop();
				if(!S.empty())	a = S.top();
				break;
			}
		}
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

	DFS(1);
	return 0;
}

/*
				1
			/		\
		2---------------3
	/		\		/		\
4--------------5  6-----------7
*/