#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    // Ver 3
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    return arr;
    
    /* Ver 1
    vector<int> :: iterator iter=arr.begin();
    for(int i=0; i<arr.size()-1;i++)
        if(arr[i]==arr[i+1])
        {   
            arr.erase(iter+i);
            i--;
        }
    return arr;
    */
    
    /* Ver 2
    vector<int> result;
    result.push_back(arr[0]);
    for(int i=0; i<arr.size();i++)
    {
        if(arr[i]!=result.back())
            result.push_back(arr[i]);
     }   

    return result;
    */
}
