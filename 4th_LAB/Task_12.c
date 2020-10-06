/*12. Дан массив М(15) вещественных чисел. Расположить элементы в обратном порядке.*/

#include <stdio.h>
#define N 15

int main()
{
	int i = 0;
	float a = 0;
	float M[N] = {0}; // = { 0.1, -0.154, 10, 100,-250.123, -222, -0.532, 1234, 0, 25.124 , 213, 0.12, -0.12, 666, 0.58123 }; // Ввод с помощью присваивания
	do 
	{
		printf("Enter %d %s",i+1,"element: ");
		scanf_s("%e", &M[i]); // Ввод массива с клавиатуры
		i++;
	} while (i < N);
	printf("Non-Reverse: ");
	for (int i = 0; i < N; i++)
		printf("%f ", M[i]);
	for (int i = 0; i < N / 2; i++)
	{
		a = M[i];
		M[i] = M[N - i - 1]; // Цикл, который разворачивает элементы массива
		M[N - i - 1] = a;
	}
		printf("\nReverse: ");
	for (int i = 0; i < N; i++)
		printf("%f ", M[i]);
	return 0;
}