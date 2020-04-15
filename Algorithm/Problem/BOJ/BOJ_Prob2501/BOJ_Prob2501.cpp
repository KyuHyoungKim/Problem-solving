#include <iostream>

int main()
{
	int N = 0, K = 0, cnt = 0;
	std::cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		if (N % i == 0)
			cnt++;
		if (cnt == K)
		{
			printf("%d\n", i);
			break;
		}
	}
	if (cnt < K)
		printf("0\n");
	return 0;
}