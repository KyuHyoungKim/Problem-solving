#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string watermelon = "수박";
    string Soo = "수";
    for(int i = 0;i< n/2; i++)
        answer += watermelon;
    if(n%2 == 1)
        answer += Soo;
    return answer;
}
