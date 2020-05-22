#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	queue<int> cards;
	int N = 0;
	cin >> N;
	if (N == 1)
		printf("1");
	else
	{
		for (int i = 1; i <= N; i++)
			cards.push(i);

		while (1) {
			cards.pop();
			if (cards.size() == 1)
				break;
			cards.push(cards.front());
			cards.pop();
		}
		printf("%d", cards.front());
	}
	return 0;
}