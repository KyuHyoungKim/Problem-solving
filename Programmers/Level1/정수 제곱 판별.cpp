#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    if(static_cast<long long>(pow(n,0.5))*static_cast<long long>(pow(n,0.5))==n)
        answer = (pow(n,0.5)+1)*(pow(n,0.5)+1);
    else
        answer = -1;
    
    return answer;
}
