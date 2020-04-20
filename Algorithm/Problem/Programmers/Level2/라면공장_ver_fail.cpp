#include <string>
#include <vector>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int Cur_Date = 0;
    int Max_Index = -1;
    for (; k - Cur_Date > stock;)
    {
        int Max_Value = 0, Max_Date = 0;
        for (int i = Max_Index + 1; (i < dates.size()) && (Cur_Date + stock >= dates[i]); i++)
        {
            if (supplies[i] > Max_Value)
            {
                Max_Value = supplies[i];
                Max_Date = dates[i];
                Max_Index = i;
            }
        }
        answer++;
        Cur_Date += Max_Date;
        stock += Max_Value - Max_Date;
    }
    return answer;
}
