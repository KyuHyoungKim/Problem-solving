#define _CRT_SECURE_NO_WARNINGS
#define IDX_MAX 1000000
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int static comp(const void* a, const void* b) {
	if (*(int*)a > *(int*) b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}

int nums[IDX_MAX] = { 0 };

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