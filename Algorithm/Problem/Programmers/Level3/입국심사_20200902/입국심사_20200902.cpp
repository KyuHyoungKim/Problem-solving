#define INF 9123456789123456789
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int N, vector<int> times) {
    long long answer = INF, mid = 0, L = 0, R;
    sort(times.begin(), times.end());
    R = (long long)times.back() * N;

    while (L <= R) {
        long long cnt = 0;
        mid = (L + R) / 2;
        for (int i = 0; i < times.size(); i++)
            cnt += mid / times[i];

        if (cnt >= N) {
            R = mid - 1;
            if (mid < answer)
                answer = mid;
        }
        else
            L = mid + 1;
    }
    return answer;
}