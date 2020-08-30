#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> Map;
    for (int i = 0; i < clothes.size(); i++)
        Map[clothes[i][1]]++;
    for (map<string, int>::iterator iter = Map.begin(); iter != Map.end(); iter++)
        answer *= (iter->second + 1);

    answer--;
    return answer;
}