#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);
    int answer = 0, N = words.size(), idx = -1;
    vector<vector<int>> graph(N);
    vector<bool> checked(N);
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++)
        if (words[i] == target) {
            idx = i;
            break;
        }

    if (idx < 0)
        return 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++) {
            int cnt = 0;

            for (int k = 0; k < begin.size(); k++)
                if (words[i][k] != words[j][k])
                    cnt++;

            if (cnt == 1) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }

    q.push(make_pair(N - 1, 0));
    checked[N - 1] = true;

    while (!q.empty()) {
        int pos = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (pos == idx) {
            answer = dist;
            break;
        }

        for (int i = 0; i < graph[pos].size(); i++) {
            int Ne = graph[pos][i];
            if (!checked[Ne]) {
                q.push(make_pair(Ne, dist + 1));
                checked[Ne] = true;
            }
        }
    }

    return answer;
}