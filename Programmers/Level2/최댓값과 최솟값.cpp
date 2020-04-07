#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    const char* str_const = s.c_str();
    char* str = new char[s.size() + 1];
    vector <int> num_list;
    
    strcpy(str, str_const);
    str = strtok(str, " ");

    for (; str != NULL;)
    {
        num_list.push_back(stoi(str));
        str = strtok(NULL, " ");
    }
    sort(num_list.begin(), num_list.end());

    answer += to_string(num_list.front());
    answer += " ";
    answer += to_string(num_list.back());

    delete[] str;
    return answer;
}
