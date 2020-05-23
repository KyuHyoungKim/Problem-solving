#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int Deque[20000] = { 0 };
int main() {
	freopen("input.txt", "r", stdin);
	int N = 0, front = 10000, back = 10000, num = 0, cnt = 0;
	char str[11];
	scanf("%d", &N);
	while (N--) {
		scanf("%s", str);
		if (str[1] == 'u') { // push
			scanf("%d", &num);
			if (!cnt) Deque[front] = num;
			else if (str[5] == 'f') {
				front--;
				Deque[front] = num;
			}
			else if (str[5] == 'b') {
				back++;
				Deque[back] = num;
			}
			cnt++;
		}
		else if (str[1] == 'o' || str[1] == 'r' || str[1] == 'a')
		{
			if (!cnt) printf("-1\n");
			else if (str[1] == 'o') { // pop
				cnt--;
				if (str[4] == 'f') {
					printf("%d\n", Deque[front]);
					if (cnt) front++;
				}
				else if (str[4] == 'b') {
					printf("%d\n", Deque[back]);
					if (cnt) back--;
				}
			}
			else if (str[1] == 'r') printf("%d\n", Deque[front]); //front
			else if (str[1] == 'a') printf("%d\n", Deque[back]); // back
		}
		else if (str[1] == 'i') printf("%d\n", cnt); //size
		else if (str[1] == 'm') printf("%d\n", !cnt); // empty
	}
	return 0;
}