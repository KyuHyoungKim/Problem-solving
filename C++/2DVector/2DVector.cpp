#include <iostream>
#include <vector>

int main(void)
{
	std::vector< std::vector <int>> A(10, std::vector<int>(5));

	printf("2D vector A[10][5]\n");
	printf("A.size() : %d\n", A.size());
	printf("A[0].size() : %d\n", A[0].size());

	return 0;
}