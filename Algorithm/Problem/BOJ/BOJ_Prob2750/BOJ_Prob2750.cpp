#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    int N = 0, temp = 0;
    std::vector<int> A;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        A.push_back(temp);
    }
    std::sort(A.begin(), A.end(), std::less<int>());

    for (int i = 0; i < N; i++)
        printf("%d\n", A[i]);
    return 0;
}