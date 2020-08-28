#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

struct Node {
	int num = 0;
	Node* PrevPnt = NULL;
	Node* NextPnt = NULL;
};

class list {
public:
	Node* pFront = NULL;
	Node* pBack = NULL;
	
	void push_back(int num) {
		Node* New = new Node;
		New->num = num;
		if (pFront == NULL && pBack == NULL) {
			pFront =  pBack = New;
		}
		else if (pFront == pBack) {
			pBack = New;
			pFront->NextPnt = pBack;
			pBack->PrevPnt = pFront;
		}
		else {
			New->PrevPnt = pBack;
			pBack->NextPnt = New;
			pBack = New;
		}
	}
	void pop_front() {
		if (pFront == pBack) {
			delete pFront;
			pFront = pBack = NULL;
		}
		else {
			pFront = pFront->NextPnt;
			delete pFront->PrevPnt;
			pFront->PrevPnt = NULL;
		}
	}
};

class queue {
public:
	list li;
	int cnt = 0;

	void push(int num) {
		li.push_back(num);
		cnt++;
	}
	void pop() {
		if (cnt) {
			printf("%d\n", li.pFront->num);
			li.pop_front();
			cnt--;
		}
		else
			printf("-1\n");
	}
	void size() {
		printf("%d\n", cnt);
	}
	void empty() {
		printf("%d\n", (bool)!cnt);
	}
	void front() {
		if (cnt)
			printf("%d\n", li.pFront->num);
		else
			printf("-1\n");
	}
	void back() {
		if (cnt)
			printf("%d\n", li.pBack->num);
		else
			printf("-1\n");
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	int N;
	queue q;
	scanf("%d", &N);
	while (N--) {
		char order[6];
		int num = 0;
		scanf("%s", order);
		if (order[1] == 'u')
			scanf("%d", &num);
		
		if (order[1] == 'u')
			q.push(num);
		else if (order[1] == 'o')
			q.pop();
		else if (order[1] == 'i')
			q.size();
		else if (order[1] == 'm')
			q.empty();
		else if (order[1] == 'r')
			q.front();
		else if (order[1] == 'a')
			q.back();
	}
	return 0;
}