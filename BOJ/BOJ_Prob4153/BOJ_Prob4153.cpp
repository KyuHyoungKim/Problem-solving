#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define TRUE 1

int IsRightTri(int* lengthArr);

int main(void)
{
	int length[3] = { 0 };

	for (;;)
	{
		scanf("%d %d %d", &length[0], &length[1], &length[2]);
		
		if (!length[0] || !length[1] || !length[2])
			break;

		if (IsRightTri(length))
			printf("right\n");
		else
			printf("wrong\n");
	}
	return 0;
}

int IsRightTri(int* lengthArr)
{
	int ret = NULL;
	int temp = 0;
	for(int i= 0; i<1; i++)
		for (int j = 0; j < 2 - i; j++)
		{
			if (lengthArr[j] > lengthArr[j + 1])
			{
				temp = lengthArr[j];
				lengthArr[j] = lengthArr[j + 1];
				lengthArr[j + 1] = temp;
			}
		}
	if (pow(lengthArr[2], 2) == pow(lengthArr[0], 2) + pow(lengthArr[1], 2))
		ret = TRUE;
	return ret;
}