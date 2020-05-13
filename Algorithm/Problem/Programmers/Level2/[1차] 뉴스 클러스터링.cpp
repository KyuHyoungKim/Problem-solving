#include <string>
#include <vector>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int J = 0, U = 0, index = 0;
    vector<int> checked(675);
    
    for (int i = 0 ; i < str1.size() - 1 ;i++) {
        if(!isalpha(str1[i]) || !isalpha(str1[i + 1]))
            continue;
        index = (31 & str1[i]) * 26 + (31 & str1[i + 1]);
        ++U;
        ++checked[index];
    }
    
    for (int i = 0 ; i < str2.size() - 1 ;i++) {
        if(!isalpha(str2[i]) || !isalpha(str2[i + 1]))
            continue;
        index = (31 & str2[i]) * 26 + (31&str2[i + 1]);

        if(checked[index]) {
            ++J;
            --checked[index];
        }
        else
            ++U;
    }
    
    if(!U)
        answer = 65536;
    else
        answer = J * 65536 / U;
    return answer;
}
