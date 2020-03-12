#ifndef _LINKED_LIST_STACK_
#define _LINKED_LIST_STACK_

typedef struct STACKDATATYPE
{
	int data;
}StackData;

typedef struct LinkedStackNodeType
{
	StackData StackData;
	struct LinkedStackNodeType* pNode;
}LinkedStackNode;

typedef struct LINKEDSTACKTYPE
{
	int CurrentNodeCount;
	LinkedStackNode* pNode;
}LinkedStack;

LinkedStack* CreateLinkedStack();
int LinkedStackPush(LinkedStack* Stack, LinkedStackNode* NewNode);
int LinkedStackPop(LinkedStack* Stack);
int LinkedStackPeak(LinkedStack* Stack);
int DeleteLinkedStack(LinkedStack* Stack);
void LinkedStackInfo(LinkedStack* Stack);


#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE 1
#define FALSE 0

#endif
