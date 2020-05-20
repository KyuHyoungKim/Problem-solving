#include <string>
#include <vector>

using namespace std;
int BF_Recursion(vector<int> numbers, int target,int Size, int checked, int sum);

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int Size = numbers.size();
    answer = BF_Recursion(numbers, target, Size, 0, 0);
    return answer;
}
int BF_Recursion(vector<int> numbers, int target,int Size, int checked, int sum)
{
    if(checked == Size)
    {
        if(target == sum)
            return 1;
        else
            return 0;
    }
    int ret = 0;   
    ret += BF_Recursion(numbers, target, Size, checked + 1, sum + numbers[checked]);
    ret += BF_Recursion(numbers, target, Size, checked + 1, sum - numbers[checked]);
    
    return ret;
}
