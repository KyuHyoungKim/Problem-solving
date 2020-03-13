#ifndef _DOUBLYLINKEDLIST_
#define _DOUBLYLINKEDLIST_

typedef struct DLListNodeType
{
	int data;
	DLListNodeType* pHead;
	DLListNodeType* pTail;

}DLListNode;

typedef struct DLListType
{
	int CurrentElementCount;
	DLListNode* HeaderNode;
}DLList;

DLList* CreateDLList();
int AddDLLElement(DLList* List, int Position, int NewElement);
void DeleteDLList(DLList* List);
int RemoveDLLElement(DLList* List, int Position);
int getDLLLength(DLList* List);
int getDLLElement(DLList* List, int Position);
void DisplayDLListElements(DLList* List);

#endif
