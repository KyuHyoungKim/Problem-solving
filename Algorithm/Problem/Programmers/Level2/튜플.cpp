#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> String_to_Vector(string s);
bool comp(const vector<int>& a, const vector<int>& b);
int FindElement(vector<int> answer, vector<int> Tuple_Subset);

vector<int> solution(string s) {
    vector<int> answer;

    vector<vector<int>> Tuple_Subsets = String_to_Vector(s);
    sort(Tuple_Subsets.begin(), Tuple_Subsets.end(), comp);

    for (int i = 0; i < Tuple_Subsets.size(); i++)
        answer.push_back(FindElement(answer, Tuple_Subsets[i]));
    return answer;
}

vector<vector<int>> String_to_Vector(string s)
{
    vector<int> Tuple;
    vector<vector<int>> Tuple_Subsets;
    string Num_String;
    int Tuple_Size = 0, Tuple_Size_Temp = 0, Tuple_First_Element = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            Num_String += s[i];
        else if (s[i] == ',' || s[i] == '}')
        {
            Tuple.push_back(stoi(Num_String));
            Num_String.clear();
            if (s[i] == '}')
            {
                Tuple_Subsets.push_back(Tuple);
                Tuple.clear();
                i += 2;
            }
        }
    }

    return Tuple_Subsets;
}

bool comp(const vector<int>& a, const vector<int>& b)
{
    return a.size() < b.size();
}

int FindElement(vector<int> answer, vector<int> Tuple_Subset)
{
    int ret = 1;

    for (int i = 0; i < Tuple_Subset.size(); ++i)
    {
        int Element = Tuple_Subset[i];
        int check = 1;
        for (int j = 0; j < answer.size(); ++j)
        {
            if (Element == answer[j])
            {
                check = 0;
                break;
            }
        }
        if (check)
        {
            ret = Element;
            break;
        }
    }

    return ret;
}
