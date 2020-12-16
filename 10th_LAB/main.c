// Ввести с клавиатуры число n. С помощью рекурсивной функции найти факториал числа n. Вывести полученное значение на экран.

#include <stdio.h>

int factorial(int n) {
	int result;
	if (n == 1 || n == 0) return(1);
	result = factorial(n - 1) * n;
	return (result);
}

int main(){
	int n = 0, result = 0;
	printf("Please, input number: ");
	scanf("%d", &n);
	result = factorial(n);
	printf("Result = %d", result);
	return 0;
}