#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int D;
	scanf("%d", &D);
	//정보	전산	미래	신양	한경	진리	형남	학생
	//0		1		2		3		4		5		6		7
	vector<long long> res = { 0,1,1,0,0,0,0,0 };

	while (--D) {
		vector<long long> temp(8);
		// 정보 : 전산,미래
		temp[0] = (res[1] + res[2]) % 1000000007;
		// 전산 : 정보, 미래, 신양
		temp[1] = (res[0] + res[2] + res[3]) % 1000000007;
		// 미래 : 정보, 전산, 신양, 한경
		temp[2] = (res[0] + res[1] + res[3] + res[4]) % 1000000007;
		// 신양 : 전산, 미래, 한경, 진리
		temp[3] = (res[1] + res[2] + res[4] + res[5]) % 1000000007;
		// 한경 : 미래, 신양, 진리, 형남
		temp[4] = (res[2] + res[3] + res[5] + res[6]) % 1000000007;
		// 진리 : 신양, 한경, 학생
		temp[5] = (res[3] + res[4] + res[7]) % 1000000007;
		// 형남 : 한경, 학생
		temp[6] = (res[4] + res[7]) % 1000000007;
		// 학생 : 진리, 형남
		temp[7] = (res[5] + res[6]) % 1000000007;
		res.swap(temp);
	}
	printf("%lld\n", res[0]);
}