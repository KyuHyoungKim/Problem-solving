#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int temp = 0;
    int cnt = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        temp = 0;
        for(int j = i ; j <= n ; j++)
        {
            temp +=j;
            if(temp >= n)
            {
                if(temp == n)
                    cnt++;
                break;
            }
        }
    }
    
    return cnt;
}
