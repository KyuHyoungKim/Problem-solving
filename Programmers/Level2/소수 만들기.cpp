#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    vector <int> NUM;
    sort(nums.begin(),nums.end(),greater<int>());
    
    int max = nums[0]+nums[1]+nums[2];
    vector<bool> Prime(max+1,true);
    Prime[0]=false; Prime[1]=false;
    
    for(int i = 2; i <= static_cast<int>(pow(max,0.5)) ; i++)
        for(int j = 2 ; i * j <=max; j++)
            if(Prime[i]==true)
                Prime[i*j]=false;
    
    for(int i = 0 ; i <nums.size()-2; i++)
        for(int j = i+1; j<nums.size()-1; j++)
            for(int k = j+1; k<nums.size(); k++)
                NUM.push_back(nums[i]+nums[j]+nums[k]);
    
    for(int i = 0 ; i<NUM.size() ; i++)
        if(Prime[NUM[i]])
            answer++;
            
    return answer;
}
