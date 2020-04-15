#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int i = 0;

bool compare(string& a, string& b)
{
    if (a[i] != b[i])
    {
        return a[i] < b[i];
    }
    else
        return a < b;
}

vector<string> solution(vector<string> strings, int n) {
    i = n;
    sort(strings.begin(), strings.end(), compare);
    return strings;
}
