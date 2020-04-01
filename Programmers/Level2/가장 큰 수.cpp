#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(string& a, string& b)
{
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector <string> num2str(numbers.size());
    for(int i = 0; i<numbers.size(); i++)
        num2str[i]=to_string(numbers[i]);
    
    sort(num2str.begin(),num2str.end(),compare);
    
    for(int i = 0; i <num2str.size();i++)
        answer += num2str[i];
    if(answer[0]=='0')
        return "0";
    return answer;
}
