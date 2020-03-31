#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long num2 = num;
    for(;num2>1 && answer < 500;)
    {
        answer++;       
        if(num2 % 2 == 0)
            num2 /= 2;
        else
            num2 = num2 * 3 + 1;
    }
    if(answer == 500)
        answer = -1;
    return answer;
}
