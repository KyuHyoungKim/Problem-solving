#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ArrayList* CreateArrayList(int MaxElementCount)
{
	if (MaxElementCount > 0)
	{
		ArrayList* NewList = (ArrayList*)malloc(sizeof(ArrayList));
		if (NewList == NULL)
		{
			printf("동적 할당 에러 1 \n");
			return NULL;
		}
		else
		{
			NewList->MaxElementCount = MaxElementCount;
			NewList->CurrentElementCount = 0;
			NewList->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode) * MaxElementCount);
		}

		if (NewList->pElement == NULL)
		{
			printf("동적 할당 에러 2 \n");
			free(NewList->pElement);
			return NULL;
		}

		memset(NewList->pElement, 0, sizeof(ArrayListNode) * MaxElementCount);
		return NewList;
	}
	else
	{
		printf("MaxElement > 0\n");
		return NULL;
	}
}

void DeleteArrayList(ArrayList* List)
{
	if (List != NULL)
	{
		memset(List->pElement, 0, sizeof(ArrayListNode) * (List->MaxElementCount));
		free(List->pElement);
		free(List);
	}
	else
		printf("List NULL");
}

int isArrayListFull(ArrayList* List)
{
	int ret = false;
	if (List != NULL)
	{
		if (List->MaxElementCount == List->CurrentElementCount)
			ret = true;
	}
	else
		printf("List NULL");

	return ret;
}

int addArrayListElement(ArrayList* List, int position, int NewElement)
{
	int ret = false;
	if (List != NULL)
	{
		if (position > 0 && position <= List->CurrentElementCount+1) {
			if (position > List->MaxElementCount)
			{
				printf("Position index error\n");
				return ret;
			}
			for (int i = List->CurrentElementCount; i > position; i--)
			{
				List->pElement[i - 1] = List->pElement[i];
			}
			List->pElement[position - 1].data = NewElement;
			List->CurrentElementCount++;
			ret = true;
		}
		else
		{
			printf("Position index error\n");
			return ret;
		}
	}

	return ret;
}

int removeArrayListElement(ArrayList* List, int Position)
{
	int ret = false;

	if (List != NULL)
	{
		if (Position > 0 && Position <= List->CurrentElementCount)
		{
			for (int i = Position; i < List->CurrentElementCount; i++)
			{
				List->pElement[i-1] = List->pElement[i];
			}
			ret = true;
			List->CurrentElementCount--;
		}
		else
		{
			printf("Position index error\n");
			return ret;
		}
	}
	printf("List NULL");
	return ret;
}

int getArrayListLength(ArrayList* List)
{
	if (List != NULL)
	{
		return List->CurrentElementCount;
	}
	printf("List NULL");
	return -1;
}

int getArrayListElement(ArrayList* List, int Position)
{
	if (List != NULL)
	{
		if (Position > 0 && Position <= List->CurrentElementCount+1)
			return List->pElement[Position - 1].data;
		else
		{
			printf("Position index error\n");
			return -1;
		}
	}
	else
	{
		printf("Position index error\n");
		return -1;
	}
}
