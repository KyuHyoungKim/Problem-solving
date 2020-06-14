#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	int A, B, C, res = 1;
	scanf("%d %d %d", &A, &B, &C);
	long long powers[32] = { 0 };
	powers[0] = A % C;
	for (int i = 1; B >= 1 << i && i < 32; i++)
		powers[i] = (powers[i - 1] * powers[i - 1]) % C;

	for (int i = 0; B >= 1 << i && i < 32; i++)
		if (B & 1 << i)
			res = res * powers[i] % C;

	printf("%d", res);

	return 0;
}