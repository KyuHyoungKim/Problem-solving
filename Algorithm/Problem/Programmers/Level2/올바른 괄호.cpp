#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int temp = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            temp++;
        else
            temp--;
        if (temp < 0)
        {
            answer = false;
            break;
        }
    }
    if (temp > 0)
        answer = false;
    return answer;
}
