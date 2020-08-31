#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int ans = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    for (; ans < citations.size(); ans++)
        if (citations[ans] <= ans) 
            break;
    return ans;
}