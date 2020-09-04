#define INF 123456789
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int res = 0;
    vector<pair<int, int>> cnt(n, { 0,0 });
    vector<vector<int>> graph(n, vector<int>(n, INF));
    for (int i = 0; i < results.size(); i++)
        graph[results[i][0] - 1][results[i][1] - 1] = 1;

    for (int i = 0; i < n; i++) //�߰���
        for (int j = 0; j < n; j++) // ����
            for (int k = 0; k < n; k++) // ����
                if (graph[j][k] > graph[j][i] + graph[i][k])
                    graph[j][k] = graph[j][i] + graph[i][k];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (graph[i][j] < INF) {
                cnt[i].second++;
                cnt[j].first++;
            }

    for (int i = 0; i < n; i++)
        if (cnt[i].first + cnt[i].second == n - 1)
            res++;

    return res;
}