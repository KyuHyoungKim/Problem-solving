#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> Min_Heap(scoville.begin(), scoville.end());
    int cnt = 0, temp = 0;
    do {
        if (Min_Heap.size() == 1)
        {
            if (Min_Heap.top() < K)
                cnt = -1;
            break;
        }
        temp = Min_Heap.top();
        Min_Heap.pop();
        temp += Min_Heap.top() * 2;
        Min_Heap.pop();
        Min_Heap.push(temp);
        cnt++;
    } while (Min_Heap.top() < K);
    return cnt;

    
    
    /* 정렬(sort function+간단한 정렬 구현)을 사용한 풀이 시간초과났다.
    int cnt = 0;
    int temp = 0;
    sort(scoville.begin(), scoville.end(), greater<int>());
    do {
        if (scoville.size() == 1)
        {
            if (scoville[0] < K)
                cnt = -1;
            break;
        }
        else
        {
            temp = scoville.back();
            scoville.pop_back();
            temp += scoville.back() * 2;
            scoville.pop_back();
            scoville.push_back(temp);
            cnt++;
            for(int j = scoville.size()-1;j>0;j--)
            {
                if(scoville[j]>scoville[j-1])
                {
                    temp = scoville[j];
                    scoville[j] = scoville[j-1];
                    scoville[j-1] = temp;
                }
                else
                    break;
            }
        }
    } while (scoville.back() < K);

    return cnt;
    */
}
