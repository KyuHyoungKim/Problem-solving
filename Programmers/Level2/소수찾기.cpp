#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void PrimeNumList(int N, vector<int>* Prime_Num)
{
    vector<int> NumList(N + 1);
    for (int i = 2; i <= N; i++)
        NumList[i] = i;

    for (int i = 2; i <= sqrt(N); i++)
    {
        if (NumList[i])
            for (int j = 2; i * j <= N; j++)
                NumList[i * j] = 0;
    }

    for (int i = 2; i <= N; i++)
        if (NumList[i])
            Prime_Num->push_back(i);
}

int solution(string numbers) {
    int answer = 0;
    int pos = 0;
    vector<int>Prime_Num;
    string temp, temp_num;
    sort(numbers.begin(), numbers.end(),greater<char>());
    PrimeNumList(stoi(numbers), &Prime_Num);

    for (int i = 0; i < Prime_Num.size(); i++)
    {
        temp = to_string(Prime_Num[i]);
        temp_num = numbers;
        for (int j = 0; j < temp.size(); j++)
        {
            pos = temp_num.find(temp[j]);
            if (pos >= 0)
                temp_num[pos] = ' ';
            else
                break;
            if (j == temp.size() - 1)
                answer++;
        }
    }
    return answer;
}
