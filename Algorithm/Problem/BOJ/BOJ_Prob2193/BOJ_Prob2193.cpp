#include <cstdio>

typedef long long ll;

int main(){
	int N;
	ll DP[91] = {0};

	scanf("%d",&N);
	
	DP[1] = 1;
	DP[2] = 1;

	for(int i = 3; i <= N; i++)
		DP[i] = DP[i - 1] + DP[i - 2];

	printf("%lld\n",DP[N]);
	return 0;
}
