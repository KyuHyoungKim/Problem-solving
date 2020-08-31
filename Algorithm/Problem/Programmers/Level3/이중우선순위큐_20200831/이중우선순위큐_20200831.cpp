#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    multiset<int,greater<int>> ms;
    int N = operations.size();
    for (int i = 0; i < N; i++) {
        char order = operations[i][0];
        int num = stoi(operations[i].substr(2));
        if (order == 'I')
            ms.insert(num);
        else {
            if (ms.empty()) continue;

            if (num > 0)
                ms.erase(ms.begin());
            else
                ms.erase(--(ms.end()));
        }
    }
    if (!ms.empty()) {
        answer[0] = *ms.begin();
        answer[1] = *(--ms.end());
    }
    return answer;
}