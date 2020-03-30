#include <string>
#include <vector>
using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    string A = "김서방은 ";
    string B = "";
    string C = "에 있다";
    for (int i = 0; i<seoul.size(); i++)
        if(!seoul[i].compare("Kim"))
        {
            B=to_string(i);
            answer = A + B + C;
            break;
        }
    
    return answer;
}
