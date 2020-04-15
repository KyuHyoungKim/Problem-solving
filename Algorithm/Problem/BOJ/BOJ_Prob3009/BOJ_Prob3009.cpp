#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int xPos[3] = { 0 }, yPos[3] = { 0 };
	int x = 0, y = 0;

	for (int i = 0; i < 3; i++)
		scanf("%d %d", &xPos[i], &yPos[i]);

	if (xPos[0] == xPos[1])
		x = xPos[2];
	else if (xPos[1] == xPos[2])
		x = xPos[0];
	else
		x = xPos[1];

	if (yPos[0] == yPos[1])
		y = yPos[2];
	else if (yPos[1] == yPos[2])
		y = yPos[0];
	else
		y = yPos[1];

	printf("%d %d\n", x, y);

	return 0;
}