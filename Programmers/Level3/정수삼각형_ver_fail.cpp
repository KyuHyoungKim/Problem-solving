#include <string>
#include <vector>
#include <algorithm>

int dp[125251];
using namespace std;
int cnt = 1;

int tri(vector<vector<int>> triangle_, int row)
{
    int last_index_of_upper_row = row * (row - 1) / 2;
    if (!dp[last_index_of_upper_row])
        tri(triangle_, row - 1);
    int temp;

    dp[last_index_of_upper_row + 1] = dp[last_index_of_upper_row + 2 - row] + triangle_[row - 1][0];
    for (int i = 2; i < row; i++)
    {
        temp = dp[last_index_of_upper_row + 1 - row + i];
        if (temp < dp[last_index_of_upper_row + 1 - row + i - 1])
            temp = dp[last_index_of_upper_row + 1 - row + i - 1];
        dp[last_index_of_upper_row + i] = temp + triangle_[row - 1][i - 1];
    }
    dp[last_index_of_upper_row + row] = dp[last_index_of_upper_row] + triangle_[row - 1][row - 1];

    cnt++;
    vector <int> results;
    if (cnt == triangle_.size())
    {
        for (int i = 1; i <= row; i++)
            results.push_back(dp[last_index_of_upper_row + i]);
        return *max_element(results.begin(), results.end());
    }
    else
        return 0;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    dp[0] = 0;
    dp[1] = triangle[0][0];

    answer = tri(triangle, triangle.size());

    return answer;
}
