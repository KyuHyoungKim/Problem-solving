#include <vector>
using namespace std;
int solution(vector<int> cookie) {
    if (cookie.size() == 1) return 0;
    int answer = 0;
    int sun1, sun2;
    for (int start = 0; start < cookie.size() - 1; start++) {
        int mid = start + 1;
        int end = mid;
        sun1 = 0;
        sun2 = 0;
        for (; mid < cookie.size(); mid++) {
            sun1 += cookie[mid - 1];
            for (; end < cookie.size() && sun2 < sun1; end++) sun2 += cookie[end];
            if (sun1 == sun2 && sun1 > answer) answer = sun1;
            sun2 -= cookie[mid];
        }
    }
    return answer;
}