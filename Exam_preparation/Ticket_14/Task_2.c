//Билет 14 - задача 2. Функция принимает массив char, некоторые из частей массива интовые числа, подсчитать их сумму и вернуть её.

#include <stdio.h>
#include <stdlib.h>

int sum(char *text){
	int sum = 0, number = 0, numBuffer = 0, dozens = 1;
	for (int i = 0; i < 128; i++)
	{
		if (text[i] >= '0' && text[i] <= '9')
		{
			dozens = 1;
			for (int j = i+1; text[j] >= '0' && text[j] <= '9'; j++) // подсчитываем кол-во десятков в числе
				dozens *= 10;
			for (; text[i] >= '0' && text[i] <= '9'; i++) // подсчитываем число в number
			{
				numBuffer = text[i] - '0';
				numBuffer *= dozens;
				dozens /= 10;
				number += numBuffer;
				numBuffer = 0;
			}
			sum += number; // складываем и переходим к следующему числу в строке
			number = 0;
		}
	}
	return(sum);
}

int main() {
	char str[128];
	printf("Please, input string: ");
	rewind(stdin);
	gets(str);
	int a = sum(str);
	printf("Sum = %d", a);
	return 1;
}
