#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Check_The_Condition(vector<string> data, string Name);

int solution(int n, vector<string> data) {
    int answer = 0;
    string Name = "ACFJMNRT";
    do{
        if (Check_The_Condition(data, Name))
            answer++;
    }while(next_permutation(Name.begin(),Name.end()));
    
    return answer;
}

int Check_The_Condition(vector<string> data, string Name)
{
    int ret = 1;
    int distance = 0;
    for (int i = data.size() - 1; i >= 0; --i)
    {
        distance = Name.find(data[i][0]) - Name.find(data[i][2]);
        if (distance < 0)
            distance *= -1;
        --distance;
        if (data[i][3] == '=' && distance == data[i][4] - '0')
            continue;
        else if (data[i][3] == '>' && distance > data[i][4] - '0')
            continue;
        else if (data[i][3] == '<' && distance < data[i][4] - '0')
            continue;
        else
            return false;
    }
    return ret;
}
