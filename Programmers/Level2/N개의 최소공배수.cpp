#include <string>
#include <vector>

using namespace std;

int Min_Common_Factor(int num1, int num2)
{
    int ret = 0;
    for (int i = 1; i <= num1; i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
            ret = i;
    }
    return ret;
}

int solution(vector<int> arr) {
    int ret = 0;
    int temp = 0;
    if (arr.size() > 1)
    {
        temp = arr[0] * (arr[1] / Min_Common_Factor(arr[0], arr[1]));
        for (int i = 1; i < arr.size() - 1; i++)
            temp *= (arr[i + 1] / Min_Common_Factor(temp, arr[i + 1]));
    }
    else
    {
        ret = arr[0];
    }
    ret = temp;
    return ret;
}
