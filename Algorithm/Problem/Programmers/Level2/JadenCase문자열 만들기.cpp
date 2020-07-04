#include <string>

using namespace std;

string solution(string s) {
    if (s[0] <= 'z' && s[0] >= 'a') s[0] += 'A' - 'a';
    for (int i = 1; i < s.size(); i++)
        if (s[i - 1] == ' ') {
            if (s[i] <= 'z' && s[i] >= 'a')
                s[i] += 'A' - 'a';
        }
        else if (s[i] <= 'Z' && s[i] >= 'A')
            s[i] -= 'A' - 'a';
    return s;
}