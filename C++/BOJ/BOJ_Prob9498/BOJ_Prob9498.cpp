#include <iostream>

int main(void)
{
	int score = 0;
	std::cin >> score;
	if (score >= 60)
	{
		if (score >= 70)
		{
			if (score >= 80)
			{
				if (score >= 90)
					printf("A");
				else
					printf("B");
			}
			else
				printf("C");
		}
		else
			printf("D");
	}
	else
		printf("F");
	return 0;
}