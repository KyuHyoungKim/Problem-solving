#include "ArrayList.h"
#include <stdio.h>

#define NumOfArrayListElement 5

int main(void)
{
	ArrayList* TestList = NULL;
	int temp = 0;

	TestList = CreateArrayList(NumOfArrayListElement);

	printf("Create Array List\n");
	printf("Max number of the list element : %d\n",TestList->MaxElementCount);
	printf("Current number of the list element : %d\n",TestList->CurrentElementCount);

	for (int i = 0; i < TestList->CurrentElementCount; i++)
	{
		temp = getArrayListElement(TestList, i+1);
		printf("%d\n", temp);
	}
	printf("\nAdd Array List Element\n");
	for (int i = 0; i < NumOfArrayListElement; i++)
	{
		addArrayListElement(TestList, i+1,i+1);
		printf("%d\n", TestList->pElement[i].data);
	}
	printf("Current number of the list element : %d\n", TestList->CurrentElementCount);
	
	printf("\nis the list full?\n%d\n",isArrayListFull(TestList));

	printf("\n Remove array list element\n");
	removeArrayListElement(TestList, 3);
	for (int i = 0; i < TestList->CurrentElementCount; i++)
	{
		printf("%d\n", TestList->pElement[i].data);
	}

	printf("\nis the list full?\n%d\n", isArrayListFull(TestList));

	printf("\nHow many element in the list?\n%d\n", getArrayListLength(TestList));

	DeleteArrayList(TestList);

	return 0;
}
