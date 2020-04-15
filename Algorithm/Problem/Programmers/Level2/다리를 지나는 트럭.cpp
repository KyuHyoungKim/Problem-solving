#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> on_bridge;
    vector<int> entering_time(truck_weights.size());    
    entering_time[0]=1;
    int time=0;
    int done=0;
    int weight_on_bridge=0;
    for(;done<truck_weights.size();)
    {
        time++;
        if(time - entering_time[done]>=bridge_length)
        {
            weight_on_bridge-=truck_weights[done];
            on_bridge.pop();
            done++;
        }
        if(done + on_bridge.size()<truck_weights.size())
            if(weight>=weight_on_bridge+truck_weights[done+on_bridge.size()])
            {
                weight_on_bridge+=truck_weights[done+on_bridge.size()];
                entering_time[done+on_bridge.size()]=time;
                on_bridge.push(truck_weights[done+on_bridge.size()]);
            }
    }
    return time;
}
