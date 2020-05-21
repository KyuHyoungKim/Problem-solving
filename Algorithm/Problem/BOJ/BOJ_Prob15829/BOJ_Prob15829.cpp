#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>

int main(void)
{
	int L = 0;
	long long res = 0;
	int Mod = 1234567891;
	long long R = 1;
	char c;

	scanf("%d", &L);
	getchar();
	for (int i = 0; i < L; i++)
	{
		scanf("%c", &c);
		res = (res + ((long long)c - 'a' + 1) * R) % Mod;
		R = (R * 31) % Mod;
	}
	printf("%d\n", res);
	return 0;
}