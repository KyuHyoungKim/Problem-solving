#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end(),greater<int>());
    int Front = 0, End = people.size() - 1;
    int Weight_Sum = 0;
    for(Front = 0;Front <= End;)
    {
        ++answer;
        Weight_Sum = 0;
        for(;Weight_Sum + people[Front] <= limit;)
        {
            Weight_Sum += people[Front];
            ++Front;
        }
        for(;Weight_Sum + people[End] <= limit;)
        {
            if(Front>End)
                return answer;
            Weight_Sum += people[End];
            --End;
        }
    }
    return answer;
}
