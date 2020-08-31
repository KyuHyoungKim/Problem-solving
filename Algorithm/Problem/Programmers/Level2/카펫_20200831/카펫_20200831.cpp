#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    for (int i = 3; i <= brown / 2 - 1; i++) {
        int j = brown / 2 + 2 - i;
        if ((i - 2) * (j - 2) == yellow) {
            answer[1] = i;
            answer[0] = j;
            break;
        }
    }
    return answer;
}