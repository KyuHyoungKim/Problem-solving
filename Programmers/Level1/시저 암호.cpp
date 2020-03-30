#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i]>='a' && s[i]<= 'z')
            s[i] = (s[i]-'a' + n)%('z'-'a'+1)+'a';
        else if(s[i]>='A' && s[i]<= 'Z')
            s[i] = (s[i]-'A'+n)%('z'-'a'+1)+'A';
    }
    return s;
}
