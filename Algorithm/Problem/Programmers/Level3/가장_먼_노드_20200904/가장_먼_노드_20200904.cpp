#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, dist = 0;
    vector<vector<int>> graph(n);
    vector<bool> visited(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    for (int i = 0; i < edge.size(); i++) {
        graph[edge[i][0] - 1].push_back(edge[i][1] - 1);
        graph[edge[i][1] - 1].push_back(edge[i][0] - 1);
    }

    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        int pos = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if (visited[pos]) continue;
        visited[pos] = true;

        if (cost > dist) {
            dist = cost;
            answer = 1;
        }
        else answer++;

        for (int i = 0; i < graph[pos].size(); i++) {
            int pos_new = graph[pos][i];
            if (visited[pos_new]) continue;
            pq.push(make_pair(pos_new, cost + 1));
        }
    }

    return answer;
}