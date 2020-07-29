#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
using namespace std;
int DP[1500001] = { 0, 1, 1 };
int main() {
    long long N = 0;
    scanf("%lld", &N);
    N %= 1500000;
    for (int i = 3; i <= N; i++)
        DP[i] = (DP[i - 1] + DP[i - 2]) % 1000000;
    printf("%d", DP[N]);
    return 0;
}