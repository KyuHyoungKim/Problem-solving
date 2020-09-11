#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int nums[1000000] = { 0 };
int comp(const void* a, const void* b) {
	int num1 = *(int*)a, num2 = *(int*)b;
	if (num1 < num2)
		return 1;
	else if (num1 > num2)
		return -1;
	else
		return 0;
}
int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);
	
	qsort(nums, N, sizeof(int), comp);

	for (int i = 0; i < N; i++)
		printf("%d\n", nums[i]);

	return 0;
}