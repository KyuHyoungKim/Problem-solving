#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    long long sum = 0;
    sort(budgets.begin(), budgets.end());
    int ret = budgets.back();

    for (int i = 0; i < budgets.size(); i++)
        sum += budgets[i];
    if (sum <= M)
        return ret;
    int exceed = sum - M, cnt = 0, temp = 0;
    do {
        ret -= temp;
        exceed -= temp * cnt;
        ++cnt;
        temp = budgets[budgets.size() - cnt] - budgets[budgets.size() - cnt - 1];
    } while (exceed > temp * cnt);

    ret -= exceed / cnt;
    if (exceed % cnt) --ret;

    return ret;
}
