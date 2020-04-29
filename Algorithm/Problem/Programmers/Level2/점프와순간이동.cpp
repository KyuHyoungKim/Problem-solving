#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    do{
        if(n%2 == 0)
            n/=2;
        else
        {
            --n;
            ans++;
        }
    }while(n>0);
    return ans;
}
