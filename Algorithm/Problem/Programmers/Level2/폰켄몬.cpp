#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
	int Species = nums.size(), answer = Species / 2;
    sort(nums.begin(), nums.end());
    for(int i = 0 ; i < nums.size()-1 ;i++)
    {
        if(nums[i] == nums[i+1])
            --Species;
    }
    if(Species < answer)
        answer = Species;
	return answer;
}
