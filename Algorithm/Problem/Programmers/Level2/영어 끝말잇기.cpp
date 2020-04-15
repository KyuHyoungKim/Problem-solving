#include <string>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    for (int i = 1; i < words.size(); i++)
    {
        if (words[i].front() != words[i - 1].back())
        {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            return answer;
        }
        for (int j = 0; j < i; j++)
        {
            if (words[j] == words[i])
            {
                answer.push_back(i % n + 1);
                answer.push_back(i / n + 1);
                return answer;
            }
        }
    }
    if (answer.empty())
        answer = { 0, 0 };
    return answer;
}
