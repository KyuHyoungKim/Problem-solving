#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
typedef long long ll;
ll sol(ll num) {
	num++;
	ll ret = 0, power_of_two = 1, temp = num;
	while (temp) {
		if (num & power_of_two)
			ret += (num - num % (power_of_two * 2)) / 2 + num % power_of_two;
		else 
			ret += (num - num % power_of_two) / 2;

		power_of_two <<=1;
		temp >>= 1;
	}
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	ll A, B, res;
	scanf("%lld %lld", &A, &B);
	res = sol(B) - sol(A - 1);
	printf("%lld", res);
	return 0;
}

/*
���ڰ� Ŀ������ ����
�ڸ������� �ش��ϴ� ũ�⸸ŭ 0�� 1�� ���� ������ �ݺ���
�̷� Ư���� ������ log2(N)�� �ð����⵵�� 1�� ������ ���� �� ����

0	0000	1
1	0001	2
2	0010	3
3	0011	4
4	0100	5
5	0101	6
6	0110	7
7	0111	8
8	1000	9
9	1001	10
10	1010	11
11	1011	12
12	1100	13
*/