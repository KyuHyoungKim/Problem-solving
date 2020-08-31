#include <string>
#include <set>
#include <vector>
using namespace std;
set<int, greater<int>> nums;
set<int> primes;
string str;
void find_nums(const string& num, int cnt, int checked) {
    if (cnt == num.size()) {
        if (!str.empty())
            nums.insert(stoi(str));
        return;
    }
    for (int i = 0; i < num.size(); i++) {
        if (checked & 1 << i) continue;
        str.push_back(num[i]);
        find_nums(num, cnt + 1, checked | 1 << i);
        str.pop_back();
        find_nums(num, cnt + 1, checked | 1 << i);
    }
}
void find_primes(int N) {
    vector<bool> check(N + 1);
    for (int i = 2; i <= N; i++) {
        if (check[i]) continue;
        primes.insert(i);
        for (int j = 2; j * i <= N; j++)
            check[i * j] = true;
    }
}
int solution(string numbers) {
    int answer = 0;
    find_nums(numbers, 0, 0);
    find_primes(*nums.begin());
    for (set<int, greater<int>> ::iterator it = nums.begin(); it != nums.end(); it++)
        if (primes.find(*it) != primes.end())
            answer++;

    return answer;
}

int main() {
    solution("123456789");
    return 0;
}