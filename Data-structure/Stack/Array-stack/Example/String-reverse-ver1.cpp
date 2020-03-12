#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArrayStackNodeType
{
	char data;
}ArrayStackNode;

typedef struct ArrayStackType
{
	int MaxElementCount;
	int CurrentElementCount;
	ArrayStackNode* pArray;
}ArrayStack;

ArrayStack* CreateStack(int MaxElementCount);
void Push(ArrayStack* Stack, char character);
int Pop(ArrayStack* Stack);
bool IsStackEmpty(ArrayStack* Stack);

int main(void)
{
	int Maximum_string_length = 0;
	printf("Maximum string length : ");
	scanf("%d", &Maximum_string_length);
	getchar();

	ArrayStack* Stack = CreateStack(Maximum_string_length);
	
	printf("Input the string : ");
	for (char A = 0; ;)
	{
		A = getchar();
		if (A == '\n')
			break;
		Push(Stack, A);
	}

	printf("Reversed String : ");
	while (IsStackEmpty(Stack) != true)
	{
		printf("%c", Pop(Stack));
	}
	printf("\n");
	return 0;
}

ArrayStack* CreateStack(int MaxElementCount)
{
	ArrayStack* pReturn = NULL;
	if (MaxElementCount > 0)
	{
		pReturn = (ArrayStack*)malloc(sizeof(ArrayStack));
		if (pReturn != NULL)
		{
			pReturn->pArray = (ArrayStackNode*)malloc(sizeof(ArrayStackNode) * MaxElementCount);
			if (pReturn->pArray != NULL)
			{
				memset(pReturn->pArray, 0, sizeof(ArrayStackNode) * MaxElementCount);
				pReturn->MaxElementCount = MaxElementCount;
				pReturn->CurrentElementCount = 0;
			}
			else
				printf("Dynamic allocation error : CreateStack\n");
		}
		else
			printf("Dynamic allocation error : CreateStack\n");
	}
	else
		printf("MaxElementCount > 0\n");
	return pReturn;
}

void Push(ArrayStack* Stack, char character)
{
	if (Stack != NULL)
	{
		if (Stack->CurrentElementCount < Stack->MaxElementCount)
		{
			Stack->pArray[Stack->CurrentElementCount].data = character;
			Stack->CurrentElementCount++;
		}
		else
			printf("Stack overflow : Push\n");
	}
	else
		printf("Stack is NULL : Push\n");
}

int Pop(ArrayStack* Stack)
{
	int ret = false;
	if (Stack != NULL)
	{
		if (IsStackEmpty(Stack) != true)
		{
			ret = Stack->pArray[Stack->CurrentElementCount-1].data;
			Stack->CurrentElementCount--;
		}
		else
			printf("Stack is empty : Pop\n");
	}
	else
		printf("Stack is NULL : Pop\n");

	return ret;
}

bool IsStackEmpty(ArrayStack* Stack)
{
	int ret = false;
	if (Stack != NULL)
	{
		if (Stack->CurrentElementCount == 0)
			ret = true;
	}
	else
		printf("Stack is NULL : IsStackEmpty\n");
	return ret;
}
