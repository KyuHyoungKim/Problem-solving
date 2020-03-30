#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(string dartResult);

int main()
{
    string str = "1S2D*3T";
    int ret = solution(str);
    printf("%d", ret);

    return 0;
}


int solution(string dartResult) {
    int score[3] = { 0 }, Region[3] = { 0 }, option[3] = { 0 }, cnt = -1;
    int answer = 0;

    for (int i = 0; i < dartResult.size(); i++)
    {
        if (dartResult[i] - '0' <= 9 && dartResult[i] - '0' >= 0)
        {
            cnt++;
            if (dartResult[i] == '1' && dartResult[i + 1] == '0')
            {
                score[cnt] = 10;
                i++;
            }
            else
                score[cnt] = dartResult[i] - '0';
        }
        else if (dartResult[i] == 'S')
            Region[cnt] = 1;
        else if (dartResult[i] == 'D')
            Region[cnt] = 2;
        else if (dartResult[i] == 'T')
            Region[cnt] = 3;
        else if (dartResult[i] == '*')
            option[cnt] = 2;
        else if (dartResult[i] == '#')
            option[cnt] = -1;
    }

    for (int i = 0; i < 3; i++)
    {
        score[i] = pow(score[i], Region[i]);
        if (option[i] != 0)
        {
            score[i] *= option[i];
            if (i >= 1 && option[i] == 2)
                score[i - 1] *= option[i];
        }
    }

    for (int i = 0; i < 3; i++)
        answer += score[i];

    return answer;
}