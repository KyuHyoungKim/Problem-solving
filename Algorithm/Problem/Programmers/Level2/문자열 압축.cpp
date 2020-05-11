#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    int New_Size = 0, Unit_Count = 0;
    string String_Unit, String_Unit_Temp, New_String;
    for (int i = 1; i <= s.size() / 2; i++)
    {
        New_String.clear();
        New_Size = 0;
        String_Unit = s.substr(0, i);
        for (int j = i; j <= s.size(); j += i)
        {
            String_Unit_Temp = s.substr(j, i);
            if (!String_Unit.compare(String_Unit_Temp))
                ++Unit_Count;
            else
            {
                if (Unit_Count)
                    New_String += to_string(Unit_Count + 1);
                New_String += String_Unit;
                String_Unit = String_Unit_Temp;
                Unit_Count = 0;
            }
        }
        if (Unit_Count)
            New_String += to_string(Unit_Count + 1);
        New_String += String_Unit;
        New_Size = New_String.size();
        if (New_Size < answer)
            answer = New_Size;
    }
    return answer;
}
