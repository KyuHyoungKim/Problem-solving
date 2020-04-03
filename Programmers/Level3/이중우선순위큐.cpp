#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>,greater<int>> empty_Min;
    priority_queue<int, vector<int>, less<int>> empty_Max;
    priority_queue<int, vector<int>, greater<int>> Min_Heap;
    priority_queue<int, vector<int>, less<int>> Max_Heap;
    int cnt = 0;
    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i][0] == 'I')
        {
            Min_Heap.push(stoi(operations[i].substr(2)));
            Max_Heap.push(stoi(operations[i].substr(2)));
            cnt++;
        }
        else if (Min_Heap.size() > 0)
        {
            if (operations[i][2] == '-')
            {
                Min_Heap.pop();
                cnt--;
            }
            else
            {
                Max_Heap.pop();
                cnt--;
            }
            if (cnt == 0)
            {
                /*
                for (int i = 0; i < Max_Heap.size(); i++)
                    Max_Heap.pop();
                for (int i = 0; i < Min_Heap.size(); i++)
                    Min_Heap.pop();
                */
                Max_Heap = empty_Max;
                Min_Heap = empty_Min;
            }
        }
    }
    if (cnt <= 0)
        answer = { 0,0 };
    else
    {
        answer.push_back(Max_Heap.top());
        answer.push_back(Min_Heap.top());
    }

    return answer;
}
