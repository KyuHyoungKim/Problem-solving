#include <string>
#include <vector>

using namespace std;

int dp[100001]={0, 1, 1};

int Fibonacci(int n)
{
    if(dp[n])
        return dp[n];
    else if(n == 0)         return 0;
    else
    {
        dp[n] = (Fibonacci(n-2) + Fibonacci(n-1))%1234567;
        return dp[n];
    }
}

int solution(int n) {
    int answer = 0;
    answer = Fibonacci(n);
    return static_cast<int>(answer);
}
