#include <string>
#include <vector>

using namespace std;
int ans = 0, N = 0, pos = 0, checked = 0;

void move() {
    int R_dist = -1, L_dist = -1;
    for (int i = 0; i < N; i++) {
        if (R_dist < 0 && !(checked & 1 << ((pos + i) % N))) {
            R_dist = i;
        }
        if (L_dist < 0 && !(checked & 1 << ((pos - i + N) % N))) {
            L_dist = i;
        }
    }

    if (R_dist <= L_dist) {
        pos = (pos + R_dist) % N;
        ans += R_dist;
    }
    else {
        pos = (pos - L_dist + N) % N;
        ans += L_dist;
    }
}

void change(string& name) {
    int up, down;
    up = name[pos] - 'A';
    down = 'Z' + 1 - name[pos];

    checked |= 1 << pos;
    ans += (up < down) ? up : down;
}

int solution(string name) {
    N = name.size();

    for (int i = 0; i < N; i++)
        if (name[i] == 'A')
            checked |= 1 << i;

    while (checked != (1<<N) - 1) {
        move();
        change(name);
    }
    return ans;
}