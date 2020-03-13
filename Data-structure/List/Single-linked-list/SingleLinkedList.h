#ifndef _SingleLinkedList_
#define _SingleLinkedList_

typedef struct SingleLinkedListNodeType
{
	int data;
	SingleLinkedListNodeType* pLink;
}SingleLinkedListNode;

typedef struct SingleLinkedListType
{
	int CurrentElementCount;
	SingleLinkedListNode HeaderNode;
}SingleLinkedList;

SingleLinkedList* CreateSingleLinkedList();
void DeleteSingleLinkedList(SingleLinkedList* List);
int IsSingleLinkedListEmpty(SingleLinkedList* List);
int AddSingleLinkedListElement(SingleLinkedList* List, int Position, int NewElement);
int RemoveSingleLinkedListElement(SingleLinkedList* List, int Position);
int GetSingleLinkedListLength(SingleLinkedList* List);
int GetSingleLinkedListElement(SingleLinkedList* List, int Position);


#endif
