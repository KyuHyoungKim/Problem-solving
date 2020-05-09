using namespace std;

int gcd(int a, int b)
{
    if(b % a == 0)
        return a;
    return gcd(b % a,a);
}

long long solution(int w,int h) {
    long long answer = 1;
    int GCD = gcd(w,h);
    answer = (long long)w * h - (w + h - GCD);
    return answer;
}
