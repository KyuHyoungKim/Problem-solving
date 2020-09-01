#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int N = money.size();
    for (int n = 0; n < 2; n++) {
        int ans = 0;
        vector<vector<int>> DP(2, vector<int>(N));
        DP[0][0] = DP[1][1] = 0;
        DP[1][n] = DP[n][1] = money[n];
        for (int i = 2; i < N - 1 + n; i++) {
            DP[0][i] = max(DP[0][i - 1], DP[1][i - 1]);
            DP[1][i] = max({ DP[0][i - 1], DP[0][i - 2], DP[1][i - 2] }) + money[i];
        }
        ans = max(DP[0][N - 2 + n], DP[1][N - 2 + n]);
        if (answer < ans) answer = ans;
    }
    return answer;
}