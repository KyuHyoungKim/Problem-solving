#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct priority_queue {
	int nums[101];
	int idx;
}priority_queue;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void push(priority_queue* pq, int num) {
	pq->nums[pq->idx] = num;

	int now = pq->idx++;
	int parent = (now - 1) / 2;

	while (now > 0 && pq->nums[now] > pq->nums[parent]) {
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
		if (pq->idx > left && pq->nums[target] < pq->nums[left])
			target = left;
		if (pq->idx > right && pq->nums[target] < pq->nums[right])
			target = right;
		if (now == target)
			break;

		swap(&pq->nums[now], &pq->nums[target]);
		now = target;
		left = now * 2 + 1;
		right = left + 1;
	}
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	int N, res = 0;
	priority_queue pq;
	memset(&pq, 0, sizeof(pq));

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		push(&pq, num);
	}

	while (pq.idx > 1) {
		int num1 = pop(&pq);
		int num2 = pop(&pq);
		push(&pq, num1 + num2);
		res += num1 * num2;
	}

	printf("%d", res);
	return 0;
}