#include <string>
#include <vector>

using namespace std;

void rotate(vector<pair<int, int>>& key, int M) {
    for (int i = 0; i < key.size(); i++) {
        int temp = key[i].first;
        key[i].first = key[i].second;
        key[i].second = M - temp - 1;
    }
}

bool solution(vector<vector<int>> key_input, vector<vector<int>> lock_input) {
    int N = lock_input.size(), M = key_input.size(), lock_cnt = 0;
    vector<pair<int, int>> key;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!lock_input[i][j])
                lock_cnt++;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            if (key_input[i][j])
                key.push_back(make_pair(i, j));

    for (int n = 0; n < 4; n++) {
        for (int y_offset = -N + 1; y_offset < N; y_offset++)
            for (int x_offset = -N + 1; x_offset < N; x_offset++) {
                int cnt = 0;
                for (int i = 0; i < key.size(); i++) {
                    int Y = key[i].first + y_offset;
                    int X = key[i].second + x_offset;

                    if (Y < 0 || Y >= N || X < 0 || X >= N)
                        continue;
                    if (lock_input[Y][X])
                        break;
                    cnt++;
                }
                if (cnt == lock_cnt)
                    return true;
            }
        rotate(key, M);
    }
    return false;
}