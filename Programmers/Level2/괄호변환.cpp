#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int Check(string str);
void function(string* w)
{
    int cnt1 = 0, cnt2 = 0;
    string u, v;
    if (w->empty() || Check(*w))
        return;

    for (int i = 0; i < w->size(); i++)
    {
        u = u + w->at(i);
        if (w->at(i) == '(')
            cnt1++;
        else
            cnt2++;
        if (cnt1 == cnt2)
            break;
    }
    v = w->substr(cnt1 + cnt2);
    function(&v);
    if (Check(u))
        *w = u + v;
    else
    {
        v = '(' + v + ')';
        string temp;
        for (int i = 1; i < u.size() - 1; i++)
        {
            if (u[i] == '(')
                temp += ')';
            else
                temp += '(';
        }
        u = temp;
        *w = v + u;
    }
}

string solution(string p) {
    function(&p);
    return p;
}

int Check(string str)
{
    int cnt = 0;
    int ret = false;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            cnt++;
        else
        {
            cnt--;
            if (cnt < 0)
                break;
        }
        if (i == str.size() - 1)
            ret = true;
    }
    return ret;
}
