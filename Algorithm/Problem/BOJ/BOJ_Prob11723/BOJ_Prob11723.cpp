#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	freopen("input.txt", "r", stdin);
	int M = 0, num = 0, element[21] = { 0 };
	char order[7];
	scanf("%d", &M);
	while (M--) {
		scanf("%s", order);
		if (order[1] == 'd') {
			scanf("%d", &num);
			element[num] = true;
		}
		else if (order[1] == 'e') {
			scanf("%d", &num);
			element[num] = false;
		}
		else if (order[1] == 'h') {
			scanf("%d", &num);
			printf("%d\n", element[num]);
		}
		else if (order[1] == 'o') {
			scanf("%d", &num);
			element[num] = !element[num];
		}
		else if (order[1] == 'l') for (int i = 1; i <= 20; i++) element[i] = true;
		else if (order[1] == 'm') for (int i = 1; i <= 20; i++) element[i] = false;
	}


	return 0;
}