#include "ArrayStack.h"
#include <stdio.h>

int main(void)
{
	ArrayStack* TestStack = CreateArrayStack(10);
	if (TestStack != NULL)
		printf("TestStack is created successfully\n\n");
	else
		return 0;

	printf("Is emtpty : %d\n", IsArrayStackEmpty(TestStack));
	printf("Is full : %d\n\n", IsArrayStackFull(TestStack));
	ViewArrayStack(TestStack);

	for (int i = 1; i <= 10; i++)
		ArrayStackPush(TestStack, i);
	ViewArrayStack(TestStack);
	printf("Is emtpty : %d\n", IsArrayStackEmpty(TestStack));
	printf("Is full : %d\n\n", IsArrayStackFull(TestStack));

	int temp = 0;
	temp = ArrayStackPop(TestStack);
	printf("Pop Result : %d\n", temp);

	temp = ArrayStackPeak(TestStack);
	printf("Peak Result : %d\n\n", temp);
	ViewArrayStack(TestStack);

	DeleteArrayStack(TestStack);

	return 0;
}
