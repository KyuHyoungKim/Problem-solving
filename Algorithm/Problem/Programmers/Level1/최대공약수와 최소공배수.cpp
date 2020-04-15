#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int MaxCommonFactor = 0;
    for(int i = 1; i<=n; i++)
        if(n%i==0 && m%i ==0)
            MaxCommonFactor = i;
    answer.push_back(MaxCommonFactor);
    answer.push_back(n*(m/MaxCommonFactor));
    return answer;
}
