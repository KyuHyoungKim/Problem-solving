#include "Graph_Matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Graph* CreateGraph(int MaxNodeCount)
{
	Graph* ret;
	ret = (Graph*)malloc(sizeof(Graph));
	ret->MaxNodeCount = MaxNodeCount;
	ret->CurrentNodeCount = 0;
	ret->NodeArr = (int*)malloc(sizeof(int) * MaxNodeCount);
	if (ret->NodeArr)
		memset(ret->NodeArr, 0, sizeof(int) * MaxNodeCount);
	else
		return NULL;
	ret->EdgeArr = (int**)malloc(sizeof(int*) * MaxNodeCount);
	if (ret->EdgeArr)
		for (int i = 0; i < MaxNodeCount; i++)
		{
			ret->EdgeArr[i] = (int*)malloc(sizeof(int) * MaxNodeCount);
			memset(ret->EdgeArr[i], 0, sizeof(int) * MaxNodeCount);
		}
	else
		return NULL;

	return ret;
}

void DeleteGraph(Graph* Gra)
{
	if (Gra)
	{
		free(Gra->NodeArr);
		for (int i = 0; i < Gra->MaxNodeCount; i++)
			free(Gra->EdgeArr[i]);
		free(Gra->EdgeArr);
		free(Gra);
	}
}

int IsFullGraph(Graph* Gra)
{
	int ret = true;
	if (Gra->MaxNodeCount > Gra->CurrentNodeCount)
		ret = false;

	return ret;
}

void AddNode(Graph* Gra, int Index)
{
	if (!Gra->NodeArr[Index])
		Gra->NodeArr[Index] = true;
	else
		printf("already used\n");
}

void DeleteNode(Graph* Gra, int Index)
{
	if (Gra->NodeArr[Index])
	{
		Gra->NodeArr[Index] = false;
		for (int i = 0; i < Gra->MaxNodeCount; i++)
		{
			Gra->EdgeArr[Index][i] = false;
			Gra->EdgeArr[i][Index] = false;
		}
	}
	else
		printf("already unused\n");
}

void AddEdge(Graph* Gra, int Head, int Tail)
{
	if (!Gra->NodeArr[Head])
	{
		printf("Head is unused\n");
		return;
	}
	if (!Gra->NodeArr[Tail])
	{
		printf("Tail is unused\n");
		return;
	}
	if (Gra->EdgeArr[Tail][Head])
	{
		printf("already used\n");
		return;
	}
	Gra->EdgeArr[Tail][Head] = true;
	Gra->EdgeArr[Head][Tail] = true;
}

void DeleteEdge(Graph* Gra, int Head, int Tail)
{
	if (!Gra->NodeArr[Head])
	{
		printf("Head is unused\n");
		return;
	}
	if (!Gra->NodeArr[Tail])
	{
		printf("Tail is unused\n");
		return;
	}
	if (!Gra->EdgeArr[Tail][Head])
	{
		printf("already usused\n");
		return;
	}
	Gra->EdgeArr[Tail][Head] = false;
	Gra->EdgeArr[Head][Tail] = false;
}

void DisplayGraph(Graph* Gra)
{
	printf("Node : \n");
	for (int i = 0; i < Gra->MaxNodeCount; i++)
		printf("%d ", Gra->NodeArr[i]);
	printf("\nEdge : \n");
	for (int i = 0; i < Gra->MaxNodeCount; i++)
	{
		for (int j = 0; j < Gra->MaxNodeCount; j++)
			printf("%d ", Gra->EdgeArr[i][j]);
		printf("\n");
	}
}