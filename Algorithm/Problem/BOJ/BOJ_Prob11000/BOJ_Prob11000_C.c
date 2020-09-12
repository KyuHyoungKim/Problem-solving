#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct pair {
	int first;
	int second;
}pair;

typedef struct priority_queue {
	int nums[200000];
	int idx;
}priority_queue;

void push(priority_queue* pq, int num);
int pop(priority_queue* pq);
int comp(const void* pair1, const void* pair2);
void swap(int* a, int* b);

int main() {
	int N;
	scanf("%d", &N);
	pair* lecs = (pair*)malloc(sizeof(pair) * N);
	priority_queue pq;
	memset(&pq, 0, sizeof(pq));
	for (int i = 0; i < N; i++)
		scanf("%d %d", &lecs[i].first, &lecs[i].second);

	qsort(lecs, N, sizeof(pair), comp);

	push(&pq, lecs[0].second);
	for (int i = 1; i < N; i++) {
		if (pq.nums[0] <= lecs[i].first)
			pop(&pq);
		push(&pq, lecs[i].second);
	}
	printf("%d", pq.idx);
	free(lecs);
	return 0;
}

void push(priority_queue* pq, int num) {
	pq->nums[pq->idx] = num;

	int now = pq->idx++;
	int parent = (now - 1) / 2;

	while (now > 0 && pq->nums[now] < pq->nums[parent]) {
		swap(&pq->nums[now], &pq->nums[parent]);
		now = parent;
		parent = (now - 1) / 2;
	}
}

int pop(priority_queue* pq) {
	int ret = pq->nums[0];
	int now = 0, left = 1, right = 2;
	int target = now;
	pq->idx--;
	pq->nums[0] = pq->nums[pq->idx];
	pq->nums[pq->idx] = 0;

	while (1) {
		if (left < pq->idx && pq->nums[target] > pq->nums[left])
			target = left;
		if (right < pq->idx && pq->nums[target] > pq->nums[right])
			target = right;
		if (target == now)
			break;

		swap(&pq->nums[now], &pq->nums[target]);
		now = target;
		left = now * 2 + 1;
		right = left + 1;
	}
	return ret;
}

int comp(const void* pair1, const void* pair2) {
	pair a = *(pair*)pair1;
	pair b = *(pair*)pair2;

	if (a.first < b.first)
		return -1;
	else if (a.first > b.first)
		return 1;
	else
		return 0;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}