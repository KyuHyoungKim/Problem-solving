#include <string>
#include <vector>
#include <math.h>

int CountPrimeNum(int num);

using namespace std;

int solution(int n) {
    int answer = CountPrimeNum(n);
    return answer;
}

int CountPrimeNum(int num){
    int cnt = 0;
    vector<bool> Number(num+1,true);
    for(int i = 2; i<=sqrt(num) ; i++)
    {
        if(Number[i] == true)
            for(int j = 2 ; i * j <= num; j++)
            {
                Number[i*j] = false;
            }
    }
    
    for(int i = 2; i<=num ; i++)
        if(Number[i]==true)
            cnt++;
    
    return cnt;
}
