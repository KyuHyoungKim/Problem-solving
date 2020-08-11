#include <vector>
#include <queue>

using namespace std;

class comp {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b ) {
        return a.second > b.second;
    }
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector < vector<pair<int, int>>> Edge(n);
    vector <bool> checked(n, false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
    for (int i = 0; i < costs.size(); i++)
    {
        Edge[costs[i][0]].push_back(make_pair(costs[i][1], costs[i][2]));
        Edge[costs[i][1]].push_back(make_pair(costs[i][0], costs[i][2]));
    }
    int here;
    for (here = 0; pq.empty(); here++)
    {
        for (int j = 0; j < Edge[here].size(); j++)
        {
            pq.push(Edge[here][j]);
        }
    }
    --here;
    checked[here] = true;
    do {
        if (!checked[pq.top().first] || !checked[here])
        {
            answer += pq.top().second;
            here = pq.top().first;
            checked[here] = true;
            pq.pop();
            for (int j = 0; j < Edge[here].size(); j++)
                pq.push(Edge[here][j]);
        }
        else
            pq.pop();

    } while (!pq.empty());

    return answer;
}
