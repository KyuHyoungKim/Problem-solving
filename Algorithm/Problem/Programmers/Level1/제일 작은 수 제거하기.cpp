#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> result;
    int pos = 0;
    vector<int> :: iterator iter = arr.begin();
    if(arr.size()==1)
        result.push_back(-1);
    else
    {
        for(int i = 1, min = arr[0];i<arr.size();i++)
            if(min>arr[i])
            {
                min = arr[i];
                pos = i;   
            }
        arr.erase(iter+pos);
        result = arr;
    }
    return result;
}
