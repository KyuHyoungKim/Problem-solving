#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N = 0, num = 0;
	scanf("%d", &N);
	vector<int> Num(10001);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		Num[num]++;
	}
	for (int i = 0; i < 10001; i++)
		if (Num[i])
			for (int j = 0; j < Num[i]; j++) 
				printf("%d\n", i);
	return 0;
}