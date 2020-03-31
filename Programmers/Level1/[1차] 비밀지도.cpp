#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string temp;
    for(int i = 0; i <n ; i ++)
    {
        temp="";
        for(int j = 0 ; j<n; j++)
        {
            if(arr1[i]>=pow(2,n-j-1) || arr2[i]>=pow(2,n-j-1))
            {
                temp.push_back('#');
                if(arr1[i]>=pow(2,n-j-1))
                    arr1[i]-=pow(2,n-j-1);
                if(arr2[i]>=pow(2,n-j-1))
                    arr2[i]-=pow(2,n-j-1);
            }
            else
                temp.push_back(' ');
        }
        answer.push_back(temp);
    }
    return answer;
}
