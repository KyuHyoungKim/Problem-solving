#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int H, width;
    int res = 0;
    scanf("%d %d", &H, &width);
    vector<int> block_height(width);
    stack<pair<int, int>> st;

    for (int i = 0; i < width; i++)
        scanf("%d", &block_height[i]);

    st.push(make_pair(0, block_height[0]));

    for (int i = 1; i < width; i++) {
        if (block_height[i] < st.top().second) {
            st.push(make_pair(i, block_height[i]));
        }
        else if (block_height[i] > st.top().second) {

            int low_idx = st.top().first;
            int low_height = st.top().second;
            int height = block_height[i];

            st.pop();
            while (!st.empty() && low_height > st.top().second) {
                low_height = min(low_height, st.top().second);
                low_idx = st.top().first;
                st.pop();
            }

            if (!st.empty()) {
                height = min(height, st.top().second);
                for (int j = low_idx; j < i; j++) {
                    if (block_height[j] < height) {
                        res += height - block_height[j];
                        block_height[j] = height;
                    }
                }

                if (block_height[i] > st.top().second)
                    i--;
                else if (block_height[i] < st.top().second)
                    st.push(make_pair(low_idx, height));
            }
            else
                st.push(make_pair(i, block_height[i]));
        }
        else {
            continue;
        }
    }

    printf("%d\n", res);

    return 0;
}