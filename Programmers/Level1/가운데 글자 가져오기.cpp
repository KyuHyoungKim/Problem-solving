#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    int STR_LEN = s.length();
    if(STR_LEN %2 ==0)
        answer = s.substr(STR_LEN/2-1,2);
    else
        answer = s.substr(STR_LEN/2,1);
    return answer;
}
