#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	int x[3], y[3], res = 0;
	for (int i = 0; i < 3; i++) 
		scanf("%d %d", &x[i], &y[i]);
	res = ((x[1] - x[0]) * (y[2] - y[0]) - (x[2] - x[0]) * (y[1] - y[0]));
	if (!res) printf("0");
	else if (res > 0) printf("1");
	else printf("-1");
	return 0;
}