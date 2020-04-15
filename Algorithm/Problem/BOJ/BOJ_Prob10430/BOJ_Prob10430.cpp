#include <iostream>

int main(void)
{
	int A = 0, B = 0, C = 0;
	std::cin >> A >> B >> C;
	std::cout << (A + B) % C << "\n";
	std::cout << ((A % C) + (B % C)) % C << "\n";
	std::cout << (A * B) % C << "\n";
	std::cout << ((A % C) * (B % C)) % C << "\n";
	return 0;
}