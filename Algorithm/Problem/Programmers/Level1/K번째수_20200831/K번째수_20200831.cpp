#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> co) {
    int N = co.size();
    vector<int> answer(N);
    for (int T = 0; T < N; T++) {
        vector<int> nums(co[T][1] - co[T][0] + 1);
        for (int i = 0; i <= co[T][1] - co[T][0]; i++)
            nums[i] = arr[co[T][0] + i];
        sort(nums.begin(), nums.end());
        answer[T] = nums[co[T][2] - 1];
    }
    return answer;
}