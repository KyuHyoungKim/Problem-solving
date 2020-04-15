#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int Burger_Price[3] = { 0 };
	int Drink_Price[2] = { 0 };
	int temp = 2000;
	int result = 0;
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &Burger_Price[i]);
		if (temp > Burger_Price[i])
			temp = Burger_Price[i];
	}
	result = temp;
	temp = 2000;
	for (int i = 0; i < 2; i++)
	{
		scanf("%d", &Drink_Price[i]);
		if (temp > Drink_Price[i])
			temp = Drink_Price[i];
	}
	result += temp;

	printf("%d", result-50);
	return 0;
}