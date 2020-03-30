#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int cnt = 0;
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i]==' ')
            cnt=-1;
        if(cnt%2==0)
        {
            if(s[i]>='a' && s[i]<='z')
                s[i]-=('a'-'A');
        }
        else
        {
            if(s[i]>='A' && s[i]<='Z')
                s[i]+=('a'-'A');
        }
        cnt++;
    }
    return s;
}
