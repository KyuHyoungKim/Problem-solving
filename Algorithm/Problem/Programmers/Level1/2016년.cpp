#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector <string> answer;
    answer.push_back("THU");
    answer.push_back("FRI");
    answer.push_back("SAT");
    answer.push_back("SUN");
    answer.push_back("MON");
    answer.push_back("TUE");
    answer.push_back("WED");    
    int day=0;
    day = (a-1)*31 + b;
    if(a >= 3)
        day-=2;
    if(a>=5)
        day--;
    if(a>=7)
        day--;
    if(a>=10)
        day--;
    if(a>=12)
        day--;
    day%=7;
    
    return answer[day];
}
