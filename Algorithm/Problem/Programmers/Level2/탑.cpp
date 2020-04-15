#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> Return;
    for(int i = heights.size()-1 ;i>=0; i--)
    {
        for(int j = i-1; j>=0; j--)
        {
            if(heights[i]<heights[j])
            {
                Return.push(j+1);
                break;
            }
            if(j==0)
                Return.push(j);
        }
    }
    Return.push(0);
    for(;!Return.empty();)
    {
        answer.push_back(Return.top());
        Return.pop();
    }
    return answer;
}
