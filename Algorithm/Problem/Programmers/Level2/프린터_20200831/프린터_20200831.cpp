#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int idx = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++)
        q.push(make_pair(priorities[i], i));
    sort(priorities.begin(), priorities.end(), greater<int>());
    while (1) {
        if (q.front().first < priorities[idx]) {
            q.push(q.front());
            q.pop();
        }
        else {
            idx++;
            if (q.front().second == location)
                break;
            q.pop();
        }
    }
    return idx;
}