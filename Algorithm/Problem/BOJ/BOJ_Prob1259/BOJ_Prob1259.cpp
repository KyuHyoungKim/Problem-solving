#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
using namespace std;
int main(void) {
	int N = 0;
	string str;
	do {
		scanf("%d", &N);
		if (N == 0)
			break;
		str = to_string(N);
		int ret = 1;
		int front = 0;
		int end = str.size() - 1;
		do {
			if (str[front] != str[end])
			{
				ret = 0;
				break;
			}
			else
			{
				++front; --end;
			}
		} while (front < end);
		if (ret)
			printf("yes\n");
		else
			printf("no\n");
	} while (1);
	return 0;
}