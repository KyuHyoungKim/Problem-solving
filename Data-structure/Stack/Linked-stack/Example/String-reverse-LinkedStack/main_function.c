#include <stdio.h>
#include <string.h>
#include "LinkedStack.h"

int main(void)
{
	char str[100] = "abcdefghijk";
	char ret[100] = { '0' };

	ReverseString(str, ret);

	printf("%s", ret);
	return 0;
}

