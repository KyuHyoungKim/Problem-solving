#include <string>
#include <vector>
using namespace std;
inline void click(string* answer, pair<int, int>* thumb, pair<int, int> pos, char LR) {
    *answer += LR;
    *thumb = pos;
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> L_thumb = { 3,0 }, R_thumb = { 3,2 };
    for (int i = 0; i < numbers.size(); i++) {
        pair<int, int> num_pos;

        if (numbers[i]) {
            num_pos.first = (numbers[i] - 1) / 3;
            num_pos.second = (numbers[i] - 1) % 3;
        }
        else
            num_pos = { 3,1 };

        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) click(&answer, &L_thumb, num_pos, 'L');
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) click(&answer, &R_thumb, num_pos, 'R');
        else {
            int L_dist = abs(L_thumb.first - num_pos.first) + abs(L_thumb.second - num_pos.second);
            int R_dist = abs(R_thumb.first - num_pos.first) + abs(R_thumb.second - num_pos.second);
            if (L_dist < R_dist || (L_dist == R_dist && !hand.compare("left"))) click(&answer, &L_thumb, num_pos, 'L');
            else click(&answer, &R_thumb, num_pos, 'R');
        }
    }
    return answer;
}