#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <list>
#include <string>
using namespace std;
char input[100001];
 int main() {
	 freopen("input.txt", "r", stdin);
	 int T, N, temp;
	 scanf("%d", &T);
	 while (T--) {
		 scanf("%s %d", input, &N);
		 string order = input;
		 list<int> arr;
		 getchar();
		 getchar();
		 for(int i = 0 ; i < N; i++)
		 {
			 scanf("%d", &temp);
			 arr.push_back(temp);
			 getchar();
		 }
		 if (!N) scanf("%s", input);
		 int k = 1, check = 1;
		 for (int i = 0; i < order.size(); i++) {
			 if (order[i] == 'R') k *= -1;
			 else if (order[i] == 'D') {
				 if (arr.empty()) {
					 printf("error\n");
					 check = 0;
					 break;
				 }
				 else if (k > 0) arr.pop_front();
				 else arr.pop_back();
			 }
		 }

		 if (check) {
			 printf("[");
			 if (k > 0) while (!arr.empty()) {
				 printf("%d", arr.front());
				 arr.pop_front();
				 if (!arr.empty()) printf(",");
			 }
			 else while (!arr.empty()) {
				 printf("%d", arr.back());
				 arr.pop_back();
				 if (!arr.empty()) printf(",");
			 }
			 printf("]\n");
		 }
	 }
	 return 0;
 }