#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    priority_queue<int> Supplies;
    int i = 0, answer = 0;

    for (; k > stock;)
    {
        for (; (i < dates.size()) && (stock >= dates[i]); i++)
            Supplies.push(supplies[i]);

        stock += Supplies.top();
        Supplies.pop();
        answer++;
    }
    return answer;
}
