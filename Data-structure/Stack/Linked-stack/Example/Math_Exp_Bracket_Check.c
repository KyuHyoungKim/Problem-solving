#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct LinkedStackNodeType
{
	char data;
	LinkedStackNodeType* pLink;
}LinkedStackNode;

typedef struct LinkedStackType
{
	int CurrentElementCount;
	LinkedStackNode* pLink;
}LinkedStack;

int BracketCheck(char Math_Exp[]);
LinkedStack* CreateStack();
void PushLLS(LinkedStack* Stack, char New_Char);
char PopLLS(LinkedStack* Stack);

int main(void)
{
	char Exp1[] = "a * (b + c) = d";
	char Exp2[] = "a * b + c) = d";
	char Exp3[] = "a * (b + c = d";

	char Exp4[] = "((A * B) / C) - {(D + E) && (F - G)}";
	char Exp5[] = "((A * B) / C - {(D + E) && (F - G))}";

	printf("%s : %d\n", Exp1, BracketCheck(Exp1));
	printf("%s : %d\n", Exp2, BracketCheck(Exp2));
	printf("%s : %d\n", Exp3, BracketCheck(Exp3));
	printf("%s : %d\n", Exp4, BracketCheck(Exp4));
	printf("%s : %d\n", Exp5, BracketCheck(Exp5));

	return 0;
}

int BracketCheck(char Math_Exp[])
{
	LinkedStack* Stack = NULL;
	int ret = TRUE;
	char temp = '0';

	Stack = CreateStack();
	for (int i = 0; i < strlen(Math_Exp); i++)
	{
		temp = 'a';
		if (Math_Exp[i] == '(' || Math_Exp[i] == '{' || Math_Exp[i] == '[')
			PushLLS(Stack, Math_Exp[i]);
		if (Math_Exp[i] == ')' || Math_Exp[i] == '}' || Math_Exp[i] == ']')
			temp = PopLLS(Stack);
		
		if (temp == NULL)
		{
			ret = FALSE;
			break;
		}
		else if (temp == '(')
		{
			if (Math_Exp[i] != ')')
			{
				ret = FALSE;
				break;
			}
		}
		else if (temp == '{')
		{
			if (Math_Exp[i] != '}')
			{
				ret = FALSE;
				break;
			}
		}
		else if (temp == '[')
		{
			if (Math_Exp[i] != ']')
			{
				ret = FALSE;
				break;
			}
		}
	}
	if (Stack->CurrentElementCount > 0)
		ret = FALSE;
	free(Stack);
	return ret;
}

LinkedStack* CreateStack()
{
	LinkedStack* pReturn = NULL;
	
	pReturn = (LinkedStack*)malloc(sizeof(LinkedStack));
	if (pReturn != NULL)
	{
		pReturn->CurrentElementCount = 0;
		pReturn->pLink = (LinkedStackNode*)malloc(sizeof(LinkedStackNode));
		if (pReturn->pLink != NULL)
		{
			pReturn->pLink->data = NULL;
			pReturn->pLink->pLink = NULL;
		}
		else
		{
			printf("Dynamic allocation error : CreateStack\n");
			free(pReturn);
			pReturn = NULL;
		}
	}
	else
		printf("Dynamic allocation error : CreateStack\n");

	return pReturn;
}

void PushLLS(LinkedStack* Stack, char New_Char)
{
	LinkedStackNode* NewNode = NULL;

	if (Stack != NULL)
	{
		NewNode = (LinkedStackNode*)malloc(sizeof(LinkedStackNode));
		if (NewNode != NULL)
		{
			NewNode->data = New_Char;
			NewNode->pLink = Stack->pLink;
			Stack->pLink = NewNode;
			Stack->CurrentElementCount++;
		}
		else
			printf("Dynamic allocation error : PushLLS\n");
	}
	else
		printf("Stack is NULL : PushLLS\n");
}

char PopLLS(LinkedStack* Stack)
{
	char ret = NULL;
	LinkedStackNode* DeletedNode = NULL;
	if (Stack != NULL)
	{
		if (Stack->CurrentElementCount > 0)
		{
			ret = Stack->pLink->data;
			DeletedNode = Stack->pLink;
			Stack->pLink = Stack->pLink->pLink;
			free(DeletedNode);
			Stack->CurrentElementCount--;
		}
		else
			printf("Stack is empty : PopLLS\n");
	}
	else
		printf("Stack is NULL : PopLLS\n");

	return ret;
}
