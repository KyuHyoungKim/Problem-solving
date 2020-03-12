#ifndef _ARRAYSTACK_
#define _ARRAYSTACK_

typedef struct ArrayStackNodeType
{
	int data;
}ArrayStackNode;

typedef struct ArrayStackType
{
	int MaxElementCount;
	int CurrentElementCount;
	ArrayStackNode* pArray;
}ArrayStack;

ArrayStack* CreateArrayStack(int MaxElementCount);
int ArrayStackPush(ArrayStack* Stack, int NewElement);
int ArrayStackPop(ArrayStack* Stack);
int ArrayStackPeak(ArrayStack* Stack);
void ViewArrayStack(ArrayStack* Stack);
int IsArrayStackFull(ArrayStack* Stack);
int IsArrayStackEmpty(ArrayStack* Stack);
int DeleteArrayStack(ArrayStack* Stack);

#endif

#define FALSE 0
#define TRUE 1
