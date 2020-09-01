#include <vector>
#include <algorithm>
using namespace std;

struct comp {
    bool operator()(const vector<int>& a, const vector<int>&b) {
        return a[1] < b[1];
    }
};

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<bool> checked(routes.size());
    sort(routes.begin(), routes.end(), comp());
    for (int i = 0; i < routes.size(); i++) {
        if (checked[i]) continue;
        answer++;
        for (int j = i + 1; j < routes.size(); j++)
            if (routes[j][0] <= routes[i][1])
                checked[j] = true;
    }
    return answer;
}