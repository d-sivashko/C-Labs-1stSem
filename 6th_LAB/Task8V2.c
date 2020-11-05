/*8. Даны действительные числа a1,…an, действительная квадратная матрица порядка n. 
Получить действительную матрицу размера n*(n+1), вставив в исходную матрицу
между j и j+1 столбцами новый столбец с элементами a1,…an..*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
	int** a, * vector;
	int i, j, k, n, m, point = 0;
	printf("Please, input Size of 2D array n: ");
	scanf_s("%d", &n); m = n;
	// Ввод элементов массива
	a = (int**)malloc(n * sizeof(int*)); // Выделение памяти на элементы строки
	for (i = 0; i < n; i++) {
		a[i] = (int*)malloc(m * sizeof(int)); // Выделение памяти под хранение строки состощей из элементов
		for (j = 0; j < m; j++) {
			printf("a[%d][%d] = ", i, j);
			fflush(stdin);
			scanf_s("%d", &a[i][j]);
		}
	}
	// Вывод массива
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%5d ", a[i][j]);
		}
		printf("\n");
	}
	// Ввод и вывод строки A
	printf("Please, input %d value of array A\n",n);
	vector = (int*)malloc(n * sizeof(int));
	for (k = 0; k < n; k++) {
		printf("Input %d value: ", k+1);
		fflush(stdin);
		scanf_s("%d", &vector[k]);
	}
	printf("Value of A are: ");
	for (k = 0; k < n; k++)
		printf("%d ", vector[k]);
	//Вставка строки А в массив n и вывод массива
	printf("\nInput column of %d you wannt put array A: ", n+1);
	scanf_s("%d", &point); point--; k = 0;
	printf("New array:\n");
	for (i = 0; i < n; i++) {
		a = (int**)realloc(a, n * sizeof(int));
		for (j = m + 1; j >= point; j--) {
			if (j == point) {
				a[i][j] = vector[k];
				k++;
			}
			else {
				a[i][j] = a[i][j - 1];
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m + 1; j++)
			printf("%5d ", a[i][j]);
		printf("\n");
	}
	// Очистка памяти 
	free(a);
	free(vector);
	return 0;
}