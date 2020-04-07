#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int temp = n;
    int n_count = 0;
    int cnt = 0;
    for (; temp > 0;)
    {
        if (temp % 2 == 1)
            n_count++;
        temp /= 2;
    }

    for (int i = n + 1; ; i++)
    {
        temp = i;
        cnt = 0;
        for (; temp > 0;)
        {
            if (temp % 2 == 1)
                cnt++;
            temp /= 2;
        }
        if (cnt == n_count)
        {
            answer = i;
            break;
        }
    }
    return answer;
}
