#include <iostream>

int MaxCommonFactor(int num1, int num2);

int main()
{
	int num1 = 0, num2 = 0;
	int ret1 = 0, ret2 = 0;
	std::cin >> num1 >> num2;
	ret1 = MaxCommonFactor(num1, num2);
	ret2 = num1 * (num2 / ret1);
	std::cout << ret1 << " " << ret2;
	return 0;
}

int MaxCommonFactor(int num1, int num2)
{
	int ret = 0;
	int min = num1;
	if (min > num2)
		min = num2;

	for (int i = 1; i <= min; i++)
	{
		if (num1 % i == 0 && num2 % i == 0)
			ret = i;
	}

	return ret;
}