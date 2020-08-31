#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> q;
    int total_weight = 0;
    int idx = 0;
    int N = truck_weights.size();
    int time = 1;

    total_weight += truck_weights[idx];
    q.push(make_pair(truck_weights[idx++], time));
    
    while (idx < N ) {
        time++;
        if (time - q.front().second >= bridge_length) {
            total_weight -= q.front().first;
            q.pop();
        }
        if (total_weight + truck_weights[idx] <= weight) {
            total_weight += truck_weights[idx];
            q.push(make_pair(truck_weights[idx++], time));
        }
    }

    time += bridge_length;

    return time;
}