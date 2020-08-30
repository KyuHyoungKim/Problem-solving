#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> Map;
    string answer;
    for (int i = 0; i < completion.size(); i++)
        Map[completion[i]]++;
    for(int i = 0 ; i < participant.size(); i++){
        Map[participant[i]]--;
        if (Map[participant[i]] < 0) {
            answer = participant[i];
            break;
        }
    }
            
    return answer;
}