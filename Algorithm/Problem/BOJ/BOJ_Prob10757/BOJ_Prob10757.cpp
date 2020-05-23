#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	int a = 0, b = 0, ten = 0, sum = 0;
	string A, B, SUM;
	cin >> A >> B;
	while (A.size() != B.size())
	{
		if (A.size() > B.size()) B = "0" + B;
		else A = "0" + A;
	}
	SUM.resize(A.size());
	for (int i = A.size() - 1; i >= 0; i--)
	{
		a = A[i] - '0';
		b = B[i] - '0';
		sum = a + b + ten;
		ten = sum / 10;
		SUM[i] = sum % 10 + '0';
		if (ten && i == 0) SUM = "1" + SUM;
	}
	cout << SUM;
	return 0;
}