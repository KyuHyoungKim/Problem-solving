#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int> nums(8);
int solution(int N, int number) {
    int answer = 10;
    queue<pair<int, int>> q;

    nums[0] = N;
    q.push(make_pair(nums[0], 1));
    for (int i = 1; i < 8; i++) {
        nums[i] = nums[i - 1] * 10 + N;
        q.push(make_pair(nums[i], i + 1));
    }
    while (!q.empty()) {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cnt > 8) continue;
        if (num == 0) continue;
        if (num == number) {
            if (answer > cnt) answer = cnt;
            continue;
        }
        for (int i = 0; i < 8 - cnt; i++) {
            q.push(make_pair(num + nums[i], cnt + i + 1));
            q.push(make_pair(num - nums[i], cnt + i + 1));
            q.push(make_pair(nums[i] - num, cnt + i + 1));
            q.push(make_pair(num * nums[i], cnt + i + 1));
            q.push(make_pair(num / nums[i], cnt + i + 1));
            q.push(make_pair(nums[i] / num, cnt + i + 1));
        }
    }
    if (answer == 10)
        answer = -1;
    return answer;
}