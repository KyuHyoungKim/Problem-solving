#include <vector>
#include <queue>
using namespace std;

vector<int> parent;

struct comp {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[2] > b[2];
    }
};

int find_parent(int X) {
    if (parent[X] == X) return X;
    else return parent[X] = find_parent(parent[X]);
}

void unionize(int idx1, int idx2) {
    idx1 = find_parent(idx1);
    idx2 = find_parent(idx2);
    if (idx1 > idx2) swap(idx1, idx2);
    parent[idx2] = idx1;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int cnt = 0;
    priority_queue<vector<int>, vector<vector<int>>, comp>pq;
    parent.resize(n);
    for (int i = 0; i < n; i++) 
        parent[i] = i;
    for (int i = 0; i < costs.size(); i++)
        pq.push(costs[i]);

    while (cnt < n - 1) {
        int node1 = pq.top()[0];
        int node2 = pq.top()[1];
        int cost = pq.top()[2];
        pq.pop();
        if (find_parent(node1) == find_parent(node2)) continue;
        answer += cost;
        cnt++;
        unionize(node1, node2);
    }
    return answer;
}