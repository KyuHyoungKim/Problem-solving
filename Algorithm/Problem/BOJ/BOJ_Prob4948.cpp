#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
	int N[100000] = { 0 };
	int temp = 0;
	int num = 0;
	int cnt = 0;

	for (num = 0; ; num++) {
		scanf("%d", &temp);
		if (temp == 0)
			break;
		N[num] = temp;
	}

	for (int i = 0; i < num; i++) {
		cnt = 0;
		for (int k = N[i]+1; k <= 2 * N[i]; k++) {
			for (int j = 2; j <= (int)ceil(sqrt((double)k)); j++) {
				if (k == 2) {
					cnt++;
					break;
				}
				if (k % j == 0)
					break;
				if (j == (int)ceil(sqrt((double)k)))
					cnt++;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}