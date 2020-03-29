#include<iostream>

int func(int num);
int min(int a1, int a2, int a3);

int DynamicProgrammingArray[1000000] = { 0 };

int main()
{
	int X = 0, i = 0;
	std::cin >> X;
	std::cout << func(X);
	return 0;
}

int func(int num)
{
	int a1 = 1000000, a2 = 1000000, a3 = 1000000;
	if (num < 2)
		return 0;

	if (DynamicProgrammingArray[num] == 0)
	{
		if (num % 3 == 0)
			a1 = func(num / 3) + 1;
		if (num % 2 == 0)
			a2 = func(num / 2) + 1;
		a3 = func(num - 1) + 1;
		DynamicProgrammingArray[num] = min(a1, a2, a3);
	}
	return DynamicProgrammingArray[num];
}

int min(int a1, int a2, int a3)
{
	int ret = a1;
	if (ret > a2)
		ret = a2;
	if (ret > a3)
		ret = a3;
	return ret;
}