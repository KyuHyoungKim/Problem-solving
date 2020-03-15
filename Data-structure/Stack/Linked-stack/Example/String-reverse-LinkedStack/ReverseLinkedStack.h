#ifndef _LINKED_LIST_STACK_
#define _LINKED_LIST_STACK_
#define TRUE 1
#define FALSE 0

typedef struct LLNodeType
{
	char data;
	struct LLNodeType* pLink;
}LLNode;

typedef struct LinkedListStackType
{
	int CurrentElementCount;
	LLNode* pLink;
}LinkedListStack;

LinkedListStack* CreateStack();
int PushLLS(LinkedListStack* Stack, char NewData);
char PopLLS(LinkedListStack* Stack);
void ReverseString(char Original_string[], char Reversed_string[]);

#endif
