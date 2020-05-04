#include "Lib0.h"
#include "string"
#include "framework.h"
#include "math.h"
#define PI acos(-1)


char* pchar()
{
	char s[] = "1";
	return s;
}

int factorial(int n)
{
	if (n >= 13) {
		return -1;
	}
	else {
		int result = 1;
		for (int i = 2; i <= n; ++i) {
			result *= i;
		}
		return result;
	}
	
}

float convert(float angle)
{
	angle = angle * PI / 180;
	return angle;
}

int F1::getA() {
	return a + 1;
}
