#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> clothes_map;
    map<string, int> ::iterator iter;
    for (int i = 0; i < clothes.size(); i++)
        clothes_map[clothes[i][1]]++;
    for (iter = clothes_map.begin(); iter != clothes_map.end(); iter++)
        answer *= (iter->second + 1);
    return answer - 1;
}