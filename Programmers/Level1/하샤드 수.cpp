#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = false;
    int divide = 0, num = x;
    for(;num>0;)
    {
        divide += num%10;
        num/=10;
    }
    if(x % divide == 0)
        answer = true;
    return answer;
}
