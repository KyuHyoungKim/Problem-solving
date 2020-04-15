#include <iostream>

int main(void)
{
	int N[3] = { 0 };
	int temp = 0;
	std::cin >> N[0] >> N[1] >> N[2];
	for(int i =0;i<3;i++)
		for(int j=0; j<2-i;j++)
			if (N[j] > N[j + 1])
			{
				temp = N[j];
				N[j] = N[j + 1];
				N[j + 1] = temp;
			}
	std::cout << N[1];
	return 0;
}