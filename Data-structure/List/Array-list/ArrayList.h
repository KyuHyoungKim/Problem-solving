#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct ArrayListNodeType
{
	int data;
}ArrayListNode;

typedef struct ArrayListType
{
	int MaxElementCount;
	int CurrentElementCount;
	ArrayListNode* pElement;
}ArrayList;

ArrayList* CreateArrayList(int MaxElementCount);
void DeleteArrayList(ArrayList* List);
int isArrayListFull(ArrayList* List);
int addArrayListElement(ArrayList* List, int position, int NewElement);
int removeArrayListElement(ArrayList* List, int Position);
int getArrayListLength(ArrayList* List);
int getArrayListElement(ArrayList* List, int Position);


#endif
