#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> clothes(n + 1, 1);
    for (int i = 0; i < lost.size(); i++) clothes[lost[i]]--;
    for (int i = 0; i < reserve.size(); i++) clothes[reserve[i]]++;
    for (int i = 1; i < n; i++) {
        if (clothes[i] == 0 && clothes[i + 1] == 2)
        {
            clothes[i]++;
            clothes[i + 1]--;
        }
        else if (clothes[i] == 2 && clothes[i + 1] == 0) {
            clothes[i]--;
            clothes[i + 1]++;
        }
    }
    for (int i = 1; i <= n; i++)
        if (clothes[i] > 0) answer++;
    return answer;
}