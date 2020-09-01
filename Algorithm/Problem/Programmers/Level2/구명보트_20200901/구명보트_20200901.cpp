#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int N = people.size();
    sort(people.begin(), people.end(), greater<int>());
    for (int i = 0, j = N-1; i <= j; i++) {
        int weight = people[i];
        while (weight < limit)
            if (weight + people[j] <= limit) {
                weight += people[j];
                j--;
            }
            else break;
        answer++;
    }

    return answer;
}