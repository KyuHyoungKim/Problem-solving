#ifndef _DEQUE_
#define _DEQUE_

typedef struct DequeNodeType
{
	char data;
	struct DequeNodeType* pLLink;
	struct DequeNodeType* pRLink;
}DequeNode;

typedef struct DequeType
{
	int CurrentElementCount;
	DequeNode* pFront;
	DequeNode* pRear;
}Deque;

Deque* CreateDeque();
void DeleteDeque(Deque* Deque);
void InsertFrontDeque(Deque* Deque, DequeNode* NewNode);
void InsertRearDeque(Deque* Deque, DequeNode* NewNode);
DequeNode ExtractFrontDeque(Deque* Deque);
DequeNode ExtractRearDeque(Deque* Deque);
void ViewDeque(Deque* Deque);


#endif