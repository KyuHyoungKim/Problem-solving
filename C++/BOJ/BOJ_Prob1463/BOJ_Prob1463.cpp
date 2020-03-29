#include<iostream>

int func(int num);

int main()
{
	int X = 0;
	std::cin >> X;
	std::cout << func(X);
	return 0;
}

int func(int num)
{
	int a1 = 0, a2 = 0, ret = 0;
	if (num < 2)
		return 0;
	
	a1 = func(num / 3) + num % 3 + 1;
	a2 = func(num / 2) + num % 2 + 1;
	ret = a1;
	if (a1 > a2)
		ret = a2;
	return ret;
}