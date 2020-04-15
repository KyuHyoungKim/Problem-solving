#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue <int> PrintList;
    vector<int> priorities_List = priorities;
    int cnt=0;
    sort(priorities_List.begin(),priorities_List.end(),greater<int>());
    
    for(int i = 0; i<priorities.size();i++)
        PrintList.push(priorities[i]);
    
    for(;!PrintList.empty();)
    {
        if(PrintList.front() == priorities_List[cnt])
        {
            PrintList.pop();
            cnt++;
            if(location == 0)
                break;
            location--;

        }
        else
        {
            PrintList.push(PrintList.front());
            PrintList.pop();
            location--;
            if(location<0)
                location = PrintList.size()-1;
        }
    }
    return cnt;
}
