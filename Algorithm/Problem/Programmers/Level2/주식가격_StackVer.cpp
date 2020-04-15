#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> time_progress;
    for(int i = 0; i<prices.size(); i++)
    {
        for(;!time_progress.empty() && prices[i]<prices[time_progress.top()];)
        {
            answer[time_progress.top()]=i-time_progress.top();
            time_progress.pop();
        }
        time_progress.push(i);
    }
    
    for(;!time_progress.empty();)
    {
        answer[time_progress.top()]=prices.size()-(time_progress.top()+1);
        time_progress.pop();
    }
    
    return answer;
}
