#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int temp = brown/2-2;
    for(int i = 1; i<temp ; i++)
        if(i * (temp - i) == red)
        {
            answer.push_back(temp - i + 2);
            break;
        }
    answer.push_back(temp - answer[0] + 4);
    return answer;
}
