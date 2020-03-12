#include "ArrayStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ArrayStack* CreateArrayStack(int MaxElementCount)
{
	ArrayStack* pReturn = NULL;
	if (MaxElementCount > 0)
	{
		pReturn = (ArrayStack*)malloc(sizeof(ArrayStack));

		if (pReturn != NULL)
		{
			pReturn->MaxElementCount = MaxElementCount;
			pReturn->CurrentElementCount = 0;
			pReturn->pArray = (ArrayStackNode*)malloc(sizeof(ArrayStackNode) * MaxElementCount);
			if (pReturn->pArray == NULL)
			{
				printf("Dynamic allocation is failed : createArrayStack\n");
				memset(pReturn, 0, sizeof(ArrayStack));
				free(pReturn);
				return NULL;
			}
			memset(pReturn->pArray, 0, sizeof(ArrayStackNode) * MaxElementCount);
		}
		else
			printf("Dynamic allocation is failed : createArrayStack\n");
	}
	else
		printf("MaxElementCount > 0 : CreateArrayStack\n");
	return pReturn;
}

int ArrayStackPush(ArrayStack* Stack,int NewElement)
{
	int ret = FALSE;
	if (Stack != NULL)
	{
		if (Stack->MaxElementCount > Stack->CurrentElementCount)
		{
			Stack->pArray[Stack->CurrentElementCount].data = NewElement;
			Stack->CurrentElementCount++;
			ret = TRUE;
		}
		else
			printf("Stack is full : ArrayStackPush\n");
	}
	else
		printf("Stack NULL : ArrayStackPush\n");
	return ret;
}

int ArrayStackPop(ArrayStack* Stack)
{
	int ret = NULL;
	if (Stack != NULL)
	{
		if (Stack->CurrentElementCount == 0)
			printf("Stack is empty : ArrayStackPop\n");
		else
		{
			ret = Stack->pArray[Stack->CurrentElementCount - 1].data;
			Stack->pArray[Stack->CurrentElementCount - 1].data = 0;
			Stack->CurrentElementCount--;
		}
	}
	else
		printf("Stack NULL : ArrayStackPop\n");
	return ret;
}

int ArrayStackPeak(ArrayStack* Stack)
{
	int ret = FALSE;

	if (Stack != NULL)
		ret = Stack->pArray[Stack->CurrentElementCount - 1].data;
	else
		printf("Stack NULL : ArrayStackPeak\n");
	return ret;
}

void ViewArrayStack(ArrayStack* Stack)
{
	if (Stack != NULL)
	{
		printf("MaxElementCount : %d\n", Stack->MaxElementCount);
		printf("CurrentElementCount : %d\n", Stack->CurrentElementCount);
		printf("Top\n");
		for (int i = Stack->CurrentElementCount - 1; i >= 0; i--)
			printf("%d\n", Stack->pArray[i].data);
		printf("\n");
	}
	else
		printf("Stack NULL : ViewArrayStack\n");
}

int IsArrayStackFull(ArrayStack* Stack)
{
	int ret = FALSE;
	if (Stack != NULL)
	{
		if (Stack->MaxElementCount == Stack->CurrentElementCount)
			ret = TRUE;
	}
	else
		printf("Stack NULL : IsArrayStackFull\n");
	return ret;
}

int IsArrayStackEmpty(ArrayStack* Stack)
{
	int ret = FALSE;
	if (Stack != NULL)
	{
		if (Stack->CurrentElementCount == 0)
			ret = TRUE;
	}
	else
		printf("Stack NULL : IsArrayStackEmpty");
	return ret;
}

int DeleteArrayStack(ArrayStack* Stack)
{
	int ret = FALSE;
	if (Stack != NULL)
	{
		if (Stack->pArray != NULL)
			free(Stack->pArray);
		else
			printf("(*Stack).pArray NULL : DeleteArrayStack\n");
		free(Stack);
		ret = TRUE;
	}
	else
		printf("Stack NULL : DeleteArrayStack\n");
	return ret;
}
