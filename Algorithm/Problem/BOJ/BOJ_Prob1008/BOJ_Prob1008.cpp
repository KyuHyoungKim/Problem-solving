#include <iostream>

int main()
{
	int A = 0, B = 0;
	std::cin >> A >> B;
	std::cout.precision(10);
	std::cout << static_cast<double>(A) / B;
	return 0;
}