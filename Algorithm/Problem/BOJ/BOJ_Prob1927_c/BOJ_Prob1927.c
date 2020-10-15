#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct Priority_Queue {
	int nums[100000];
	int idx;
}PQ;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void push(PQ* pq, int num) {
	pq->nums[pq->idx] = num;
	int now = pq->idx++;
	int parent = (now - 1) / 2;

	while (now > 0 && pq->nums[now] < pq->nums[parent]) {
		swap(&pq->nums[now], &pq->nums[parent]);
		now = parent;
		parent = (now - 1) / 2;
	}
}
void pop(PQ* pq) {
	if (pq->idx == 0) {
		printf("0\n");
		return;
	}
	printf("%d\n", pq->nums[0]);
	pq->idx--;
	pq->nums[0] = pq->nums[pq->idx];

	int now = 0, Lchild = 1, Rchild = 2;
	int target = now;

	while (1) {
		if (Lchild < pq->idx && pq->nums[Lchild] < pq->nums[target])
			target = Lchild;
		if (Rchild < pq->idx && pq->nums[Rchild] < pq->nums[target])
			target = Rchild;
		if (target == now)
			break;

		swap(&pq->nums[now], &pq->nums[target]);
		now = target;
		Lchild = now * 2 + 1;
		Rchild = Lchild + 1;
	}
}
int main() {
	freopen("input.txt", "r", stdin);

	int N;
	PQ pq;

	scanf("%d", &N);
	memset(&pq, 0, sizeof(PQ));

	while (N--) {
		int num;
		scanf("%d", &num);
		if (num) 
			push(&pq, num);
		else 
			pop(&pq);
	}

	return 0;
}