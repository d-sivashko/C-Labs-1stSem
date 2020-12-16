// Фибоначчи рекурсией. В Main вывести числа.

#include <stdio.h>

int fibonacci(int N)  // рекурсивная функция
{
    if (N == 1 || N == 2)
        return 1; // первые 2 числа равны 1
    return fibonacci(N - 1) + fibonacci(N - 2); // складываем предыдущие 2 числа
}

int main()
{
    int N;
    printf("N=");
    scanf("%d", &N); // вводим число N
    for (int i = 1; i <= N; i++) // В цикле выводим N чисел Фибоначчи
        printf("%d ", fibonacci(i));
    return 0;
}