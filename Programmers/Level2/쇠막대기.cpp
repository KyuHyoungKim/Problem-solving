#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<bool> rod;
    
    for(int i = 0 ; i < arrangement.size(); i++)
    {
        if(arrangement[i]=='(')
            rod.push(true);
        else
        {
            rod.pop();
            if(arrangement[i-1]=='(')
                answer+=rod.size();
            else
                answer++;
        }
    }
    
    return answer;
}
