#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
int main(void)
{
	int R = 0;

	scanf("%d", &R);

	printf("%lf\n%lf\n", pow(R, 2) * (double)M_PI,2*pow(R,2));
	return 0;
}