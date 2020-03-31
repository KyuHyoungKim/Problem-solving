#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int num = 0;
    for(;n>0;)
    {
        n-=1;
        num = n%3;
        if(num == 2)
            num++;
        num++;
        answer = to_string(num) + answer;
        n/=3;
    }
    return answer;
}
