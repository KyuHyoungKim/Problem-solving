#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string str = number;
    int cnt = 0;
    for(int i = 0 ; i < str.size(); i++)
    {
        for(int j = i+1 ; j < i+1+k-cnt && j < str.size() ; j ++)
        {
            if(str[i]<str[j])
            {
                str.erase(i,1);
                cnt++;
                i--;
                if(cnt == k)
                    return str;
                break;
            }
        }
    }
    if(cnt<k)
        str.erase(str.size()+cnt-k,k-cnt);
    return str;
}
