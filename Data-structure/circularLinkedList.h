#ifndef _CIRCULARLINKEDLIST_
#define _CIRCULARLINKEDLIST_

typedef struct CLListNodeType
{
	int data;
	CLListNodeType* pLink;
}CLListNode;

typedef struct CLListType
{
	int CurrentElementCount;
	CLListNode HeaderNode;
}CLList;

CLList* CreateCLList();
int AddCLListElement(CLList* List, int Position, int NewElement);
int RemoveCLListElement(CLList* List, int Position);
int isCLListEmpty(CLList* List);
void DeleteCLList(CLList* List);
int getCLListLenght(CLList* List);
int getCLListElement(CLList* List, int Position);
void ViewAllCLListElements(CLList* List);


#endif
