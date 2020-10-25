#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int cnt = 0;
    string str;
    stack<pair<int,int>> st;

    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            st.push(make_pair(cnt - 1, str[i - 1] - '0'));
            cnt = 0;
        }
        else if (str[i] == ')') {
            int inner_size = st.top().first;
            int product_num = st.top().second;
            st.pop();
            cnt *= product_num;
            cnt += inner_size;
        }
        else
            cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}