#define INF 123456789
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    int N = numbers.size();
    vector<string> nums(N);
    for (int i = 0; i < N; i++) 
        nums[i] = to_string(numbers[i]);
    sort(nums.begin(), nums.end(), comp);

    for (int i = 0; i < N; i++)
        answer += to_string(stoi(nums[i]));
    if (answer[0] == '0')
        answer = "0";
    return answer;
}