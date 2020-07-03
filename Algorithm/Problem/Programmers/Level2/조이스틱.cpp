#include <string>
#include <vector>

using namespace std;
pair<int, int> find_pos(string& name, string& temp, int K, int now_pos) {
    pair<int, int> ret; //pos, dist
    ret.first = now_pos;
    while (temp[ret.first] == name[ret.first]) {
        ret.first += K;
        ret.second++;
        if (ret.first == name.size())
            ret.first -= name.size();
        else if (ret.first < 0)
            ret.first += name.size();
    }
    return ret;
}
int solution(string name) {
    int answer = 0, pos = 0;
    string temp;
    for (int i = 0; i < name.size(); i++) temp += 'A';
    while (1) {
        int cnt1 = abs(name[pos] - temp[pos]), cnt2 = abs(temp[pos] + 'Z' - 'A' + 1 - name[pos]);
        int cnt = (cnt1 < cnt2) ? cnt1 : cnt2;
        answer += cnt;
        temp[pos] = name[pos];
        if (!name.compare(temp)) break;

        int moved_L = pos, count_L = 0;
        pair<int, int> Left = find_pos(name, temp, -1, pos);
        pair<int, int> Right = find_pos(name, temp, 1, pos);
        pair<int, int> move = (Left.second < Right.second) ? Left : Right;
        answer += move.second;
        pos = move.first;
    }
    return answer;
}