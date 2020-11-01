/*8. Даны действительные числа a1,…an, действительная квадратная матрица порядка n.
Получить действительную матрицу размера n*(n+1), вставив в исходную матрицу между
j и j+1 столбцами новый столбец с элементами a1,…an..*/

#include <stdio.h>
#define N 4

int main() {
	int A[N][N] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} }; // инициализация и заполнение оригинального массива
	int * p = A;
	printf("Original Array:\n");
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}

	int column = 0; // ввод столбца, который мы хотим добавить
	printf("\nEnter number of column: ");
	scanf_s("%d", &column);
	column--;

	int elements[N] = { 7,3,5,6 };// действительные числа а1,... аn
	int* k = elements;

	int B[N][N + 1]; // добавление в исходный массив ещё одного столбца
	printf("\nNew Array:\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N + 1; j++) {
			if (j == column) {
				B[i][j] = *k;
				k++;
			}
			else {
				B[i][j] = *p;
				p++;
			}
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}

	return 0;
}