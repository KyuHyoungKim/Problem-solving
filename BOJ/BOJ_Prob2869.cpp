#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int A = 0;
	int B = 0;
	int V = 0;
	int result = 0;
	int temp = 0;
	scanf("%d %d %d", &A, &B, &V);

	result = (V-A)/(A-B);
	temp = (V - A) % (A - B) + A;
	for (int i = 0; temp >= 0; i++) {
		result++;
		temp = temp - A;
		if (temp <= 0) { break; }
		temp = temp + B;
	}

	printf("%d", result);

	return 0;
}
