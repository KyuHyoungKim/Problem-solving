#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> Prog_Queue;
    queue<int> Speed_Queue;
    int cnt=0;
    for(int i = 0; i<progresses.size(); i++)
    {
        Prog_Queue.push(progresses[i]);
        Speed_Queue.push(speeds[i]);   
    }
    
    for(int time = 0;!Prog_Queue.empty();time++)
    {
        cnt = 0;
        for(;Prog_Queue.front()+time*Speed_Queue.front()>=100;)
        {
            cnt++;
            Prog_Queue.pop();
            Speed_Queue.pop();
        }
        if(cnt>0)
            answer.push_back(cnt);
    }
    return answer;
}
