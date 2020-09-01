#include <vector>
#include <algorithm>
using namespace std;
vector<int> parent;

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

int solution(int n, vector<vector<int>> computers) {
    int answer = 1;
    parent.resize(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (computers[i][j])
                unionize(i, j);

    for (int i = 0; i < n; i++)
        find_parent(i);
    sort(parent.begin(), parent.end());
    for (int i = 1; i < n; i++)
        if (parent[i] != parent[i - 1])
            answer++;

    return answer;
}