#include <iostream>
using namespace std;
int main() {
	int N = 0, cnt = 0, i = 665, temp = 0;
	cin >> N;
	do {
		i++;
		temp = i;
		while (temp >= 666) {
			if ((temp % 1000) == 666) {
				cnt++;
				break;
			}
			else temp /= 10;
		}
	} while (N != cnt);
	printf("%d\n", i);
	return 0;
}