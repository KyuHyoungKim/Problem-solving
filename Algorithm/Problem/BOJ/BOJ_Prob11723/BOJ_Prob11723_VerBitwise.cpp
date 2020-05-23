#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	freopen("input.txt", "r", stdin);
	int M = 0, num = 0, element = 0;
	char order[7];
	scanf("%d", &M);
	while (M--) {
		scanf("%s", order);
		if (order[1] == 'l') element = (1 << 22) - 1;
		else if (order[1] == 'm') element = 0;
		else {
			scanf("%d", &num);
			if (order[1] == 'd') element |= 1 << num;
			else if (order[1] == 'e' && element & (1 << num)) element -= (1 << num);
			else if (order[1] == 'h') printf("%d\n", (bool)(element & (1 << num)));
			else if (order[1] == 'o') {
				if (element & (1 << num)) element -= (1 << num);
				else element |= (1 << num);
			}
		}
	}
	return 0;
}