#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            for (int k = 1; k <= 9; k++) {
                if (i == j || j == k || k == i) continue;
                bool check = true;
                for (int n = 0; n < baseball.size(); n++) {
                    int a = baseball[n][0] / 100;
                    int b = (baseball[n][0] % 100) / 10;
                    int c = baseball[n][0] % 10;

                    int strike = 0, ball = 0;
                    if (i == a) strike++;
                    else if (i == b || i == c) ball++;

                    if (j == b) strike++;
                    else if (j == a || j == c) ball++;

                    if (k == c) strike++;
                    else if (k == a || k == b) ball++;

                    if (strike != baseball[n][1] || ball != baseball[n][2]) {
                        check = false;
                        break;
                    }
                }
                if (check) answer++;
            }
    return answer;
}