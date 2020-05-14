#include <string>
#include <vector>

using namespace std;

int Find_Cases(vector<string> data, string Line, int checked, string Name);
int Check_The_Condition(vector<string> data, string Line, string Name);

int solution(int n, vector<string> data) {
    int answer = 0;
    int checked = 0;
    string Line;
    string Name = "ACFJMNRT";
    answer = Find_Cases(data, Line, checked, Name);
    return answer;
}

int Find_Cases(vector<string> data, string Line, int checked, string Name)
{
    int ret = 0;
    if (checked == (1 << 8) - 1)
    {
        if (Check_The_Condition(data, Line, Name))
            ret = 1;
        return ret;
    }
    else
    {
        for (int i = 0; i < 8; ++i)
        {
            if (!(checked & 1 << i))
                ret += Find_Cases(data, Line + Name[i], checked | 1 << i, Name);
        }
    }
    return ret;
}

int Check_The_Condition(vector<string> data, string Line, string Name)
{
    int ret = 1;
    int Index[2] = { 0 };
    int distance = 0;
    for (int i = 0; i < data.size(); i++)
    {
        Index[0] = Line.find(data[i][0]);
        Index[1] = Line.find(data[i][2]);
        distance = Index[0] - Index[1];
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
