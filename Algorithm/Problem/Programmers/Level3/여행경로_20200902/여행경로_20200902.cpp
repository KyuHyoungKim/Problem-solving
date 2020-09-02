#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> answer;
bool DFS(map<string, vector<string>>& m, map<string, vector<bool>>& used, string pos, int cnt, int N) {
    answer.push_back(pos);

    if (cnt == N)
        return true;

    bool flag = false;
    for (int i = 0; i < m[pos].size(); i++) {
        if (used[pos][i]) continue;
        used[pos][i] = true;
        flag = DFS(m, used, m[pos][i], cnt + 1, N);
        used[pos][i] = false;
        if (flag) break;
    }

    if (!flag)
        answer.pop_back();

    return flag;
}
vector<string> solution(vector<vector<string>> tickets) {
    int N = tickets.size();
    map<string, vector<string>> m;
    map<string, vector<bool>> used;

    for (int i = 0; i < tickets.size(); i++) {
        m[tickets[i][0]].push_back(tickets[i][1]);
        used[tickets[i][0]].push_back(false);
    }

    for (map<string, vector<string>>::iterator it = m.begin(); it != m.end(); it++)
        sort(it->second.begin(), it->second.end(), less<string>());

    DFS(m, used, "ICN", 0, N);

    return answer;
}