#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int Queue[10001] = { 0 };
int main()
{
	freopen("input.txt", "r", stdin);
	int N = 0, front = 0, cnt = 0, num = 0;
	char order[7];
	scanf("%d", &N);
	while (N--) {
		scanf("%s", order);
		if (order[1] == 'u') { // push
			scanf("%d", &num);
			Queue[cnt++] = num;
		}
		else if (order[1] == 'o' || order[1] == 'r' || order[1] == 'a')	// pop , front, back
		{
			if (cnt == front)
				printf("-1\n");
			else if (order[1] == 'o') printf("%d\n", Queue[front++]);
			else if (order[1] == 'r') printf("%d\n", Queue[front]);
			else if (order[1] == 'a') printf("%d\n", Queue[cnt - 1]);
		}
		else if (order[1] == 'i') printf("%d\n", cnt - front); 	// size
		else if (order[1] == 'm') printf("%d\n", cnt == front); // empty
	}
	return 0;
}