#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> pud) {
    int answer = 0;
    vector<vector<int>> Map(n, vector<int>(m));
    for (int i = 0; i < pud.size(); i++)
        Map[pud[i][1] - 1][pud[i][0] - 1] = -1;

    for (int i = 0; i < m; i++) {
        if (Map[0][i] < 0)
            break;
        Map[0][i] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (Map[i][0] < 0)
            break;
        Map[i][0] = 1;
    }

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) {
            if (Map[i][j] < 0)
                continue;
            if (Map[i - 1][j] > 0)
                Map[i][j] += Map[i - 1][j];
            if (Map[i][j - 1] > 0)
                Map[i][j] += Map[i][j - 1];
            Map[i][j] %= 1000000007;
        }
    answer = Map[n - 1][m - 1];
    return answer;
}