#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int D;
	scanf("%d", &D);
	//����	����	�̷�	�ž�	�Ѱ�	����	����	�л�
	//0		1		2		3		4		5		6		7
	vector<long long> res = { 0,1,1,0,0,0,0,0 };

	while (--D) {
		vector<long long> temp(8);
		// ���� : ����,�̷�
		temp[0] = (res[1] + res[2]) % 1000000007;
		// ���� : ����, �̷�, �ž�
		temp[1] = (res[0] + res[2] + res[3]) % 1000000007;
		// �̷� : ����, ����, �ž�, �Ѱ�
		temp[2] = (res[0] + res[1] + res[3] + res[4]) % 1000000007;
		// �ž� : ����, �̷�, �Ѱ�, ����
		temp[3] = (res[1] + res[2] + res[4] + res[5]) % 1000000007;
		// �Ѱ� : �̷�, �ž�, ����, ����
		temp[4] = (res[2] + res[3] + res[5] + res[6]) % 1000000007;
		// ���� : �ž�, �Ѱ�, �л�
		temp[5] = (res[3] + res[4] + res[7]) % 1000000007;
		// ���� : �Ѱ�, �л�
		temp[6] = (res[4] + res[7]) % 1000000007;
		// �л� : ����, ����
		temp[7] = (res[5] + res[6]) % 1000000007;
		res.swap(temp);
	}
	printf("%lld\n", res[0]);
}