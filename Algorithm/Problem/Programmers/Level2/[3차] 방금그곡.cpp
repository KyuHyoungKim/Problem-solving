#include <string>
#include <vector>

using namespace std;
void Capital_to_Small_Letter(string* str);
int Calculate_Play_Time(string musicinfos);

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    Capital_to_Small_Letter(&m);
    int Max_Time = 0;
    for (int i = 0; i < musicinfos.size(); i++)
    {
        int PlayTime = Calculate_Play_Time(musicinfos[i]);

        if (PlayTime > Max_Time)
        {
            int Note_index = musicinfos[i].find_last_of(',');
            string Note = musicinfos[i].substr(Note_index + 1);
            Capital_to_Small_Letter(&Note);

            string Note_unit = Note;
            int Note_Length = Note.size();

            if ((PlayTime - Note_Length) > 0)
            {
                for (int j = 0; j < (PlayTime - Note_Length) / Note_Length; j++)
                    Note += Note_unit;
                for (int j = 0; j < (PlayTime - Note_Length) % Note_Length; j++)
                    Note += Note_unit[j];
            }
            else
                for (int j = 0; j < Note_Length - PlayTime; j++)
                    Note.pop_back();

            if ((int)Note.find(m) >= 0)
            {
                string title;
                for (int j = 12; j < Note_index; j++)
                    title += musicinfos[i][j];
                answer = title;
                Max_Time = PlayTime;
            }
        }
    }

    return answer;
}

void Capital_to_Small_Letter(string* str)
{
    for (;;)
    {
        int index = str->find("#");
        if (index >= 0)
        {
            string temp;
            temp += str[0][index - 1] - ('A' - 'a');
            str->replace(index - 1, 2, temp);
        }
        else
            break;
    }
}

int Calculate_Play_Time(string musicinfos)
{
    vector<string> time(4);
    time[0] += musicinfos[0];
    time[0] += musicinfos[1];
    time[1] += musicinfos[3];
    time[1] += musicinfos[4];
    time[2] += musicinfos[6];
    time[2] += musicinfos[7];
    time[3] += musicinfos[9];
    time[3] += musicinfos[10];
    int PlayTime = (60 * stoi(time[2]) + stoi(time[3])) - (60 * stoi(time[0]) + stoi(time[1]));
    return PlayTime;
}
