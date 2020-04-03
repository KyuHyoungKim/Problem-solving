#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> cnt(3);
    int A[] = { 1,2,3,4,5 };
    int B[] = { 2,1,2,3,2,4,2,5 };
    int C[] = { 3,3,1,1,2,2,4,4,5,5 };
    int size[3] = { 5, 8, 10 };
    for (int i = 0; i < answers.size(); i++)
    {
        if (A[i % size[0]] == answers[i])
            cnt[0]++;
        if (B[i % size[1]] == answers[i])
            cnt[1]++;
        if (C[i % size[2]] == answers[i])
            cnt[2]++;
    }

    int max = *max_element(cnt.begin(), cnt.end());
    for (int i = 0; i < 3; i++)
        if (cnt[i] == max)
            answer.push_back(i + 1);
    return answer;
}
