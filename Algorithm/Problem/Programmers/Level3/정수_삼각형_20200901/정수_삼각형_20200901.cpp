#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int N = triangle.size();
    vector<vector<int>> DP(N, vector<int>(N, 0));
    DP[0][0] = triangle[0][0];
    for (int i = 1; i < N; i++)
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                DP[i][j] = DP[i - 1][j] + triangle[i][j];
            else if (j == i)
                DP[i][j] = DP[i - 1][j - 1] + triangle[i][j];
            else
                DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + triangle[i][j];
        }

    for (int i = 0; i < N; i++)
        if (answer < DP[N - 1][i])
            answer = DP[N - 1][i];
    return answer;
}