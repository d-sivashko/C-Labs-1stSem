// Билет 9 - задача 1. Написать функцию перевода числа(десятичнойдроби) в другую систему счисления(2 или 16)

#include <stdio.h>
#include <stdlib.h>

void binaryFunc(float x)
{
	int i = 0, xInt = x, *intBin = NULL, count = 1, ostBin[4];
	float ost = x - xInt;
	printf("\nBin system: ");
	do {
		intBin = realloc(intBin, count * sizeof(int));
		if (xInt % 2 != 0)
			intBin[i] = 0;
		else
			intBin[i] = 1;
		printf("%d", intBin[i]);
		xInt /= 2;
		count++;
		i++;
	} while (xInt >= 1);
	if (ost != 0)
	{
		printf(".");
		for (i = 0; i < 4; i++)
		{
			ost *= 2;
			if (ost >= 1)
			{
				ostBin[i] = 1;
				ost -= 1;
			}
			else
			{
				ostBin[i] = 0;
			}
			printf("%d", ostBin[i]);
		}
	}
	free(intBin);
}

void hexFunc(float x) {
	int hex = x;
	printf("\nHex system: %X", hex);
}

int main() 
{
	float num = 12.825;
	printf("Dec system: %g", num);
	binaryFunc(num);
	hexFunc(num);
	return 0;;
}