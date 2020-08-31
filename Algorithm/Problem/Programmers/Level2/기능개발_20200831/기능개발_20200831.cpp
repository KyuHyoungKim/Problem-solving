#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int cnt = 0, N = speeds.size();
    vector<int> answer;
    while (cnt < N) {
        int ans = 0;
        for (int i = cnt; i < N; i++) 
            progresses[i] += speeds[i];
        while (cnt < N && progresses[cnt] >= 100) {
            ans++;
            cnt++;
        }
        if (ans)
            answer.push_back(ans);
    }

    return answer;
}