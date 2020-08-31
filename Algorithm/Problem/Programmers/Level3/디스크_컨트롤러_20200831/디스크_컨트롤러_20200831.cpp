#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct comp{
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int N = jobs.size();
    int time = 0;
    int idx = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;

    sort(jobs.begin(), jobs.end(), comp());
    while (idx != N) {
        time = jobs[idx][0];
        while (idx < N && time >= jobs[idx][0]) {
            pq.push(make_pair(jobs[idx][0], jobs[idx][1]));
            idx++;
        }

        while (!pq.empty()) {
            int st = pq.top().first;
            int cost = pq.top().second;
            pq.pop();

            time += cost;
            answer += time - st;

            while (idx < N && time >= jobs[idx][0]) {
                pq.push(make_pair(jobs[idx][0], jobs[idx][1]));
                idx++;
            }
        }
    }
    answer /= N;
    return answer;
}

int main() {
    vector<vector<int>> jobs = {{0, 9}, {0, 4}, {0, 5}, {0, 7}, {0, 3}};
    solution(jobs);

    return 0;
}