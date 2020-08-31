#include <string>
#include <vector>

using namespace std;

string solution(string num, int k) {
    int idx = 0;
    for (int i = 0; i < k; i++) {
        int j = idx;
        int fin = num.size() - 1;
        for (; j < fin; j++)
            if (num[j] < num[j + 1]) {
                num.erase(j, 1);
                if (j > 0)
                    idx = j - 1;
                break;
            }
        if (j == fin)
            num.pop_back();
    }
    return num;
}