#include <string>
#include <vector>

using namespace std;

long long dp[81];

long long solution(int N) {
    if(dp[N])
        return dp[N];
    else
    {
        if(N==1)
            dp[N]=4;
        else if(N==2)
            dp[N]=6;
        else if(N>2)
            dp[N] = solution(N-2)+solution(N-1);
        return dp[N];
    }
}
