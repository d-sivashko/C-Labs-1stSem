// Билет 14 - задача 1. Перевод дробной части числа из 1 системы счисления в другую.

#include <stdio.h>
#include <stdlib.h>

int main() {
	float num = 12.875, ost = 0, binSystem = 0;
	int numInt = num;
	ost = num - numInt;
	printf("Number before transition: %g", ost);
	printf("\nNumber after transition to binary system: 0.");
	int binarySystem[4];
	for (int i = 0; i < 4; i++) 
	{
		ost *= 2;
		if (ost >= 1)
		{
			binarySystem[i] = 1;
			ost -= 1;
		}
		else 
		{
			binarySystem[i] = 0;
		}
		printf("%d", binarySystem[i]);
	}
	return 0;
}