/*Ввести с клавиатуры число. Написать функцию, которая определяет четность числа.
 Если число четное – разделить его на два, если нечетное – оставить как есть.
 Написать функцию, которая находит процент от числа. Результат вычислений вывести на экран.*/  

#include <stdio.h>
#include <stdlib.h>

int checkFunc(int num)
{
    if (num % 2 == 0) {
        printf("\nYour number is EVEN");
    }
    else {
        printf("\nYour number is ODD");
        num++;
    }
    return num;
}

float percentFunc(int num)
{
    float percentFromNum = 0, percent = 0;
    printf("\nInput b: ");
    scanf_s("%f", &percent);
    percentFromNum = num * (percent / 100);
    int a = (int)percentFromNum;
    printf("\nPercent from num = %g", percentFromNum);
}

int main()
{
    float n = 0, b = 0;
    printf("Input n: ");
    scanf_s("%f", &n);
    n = checkFunc(n);
    percentFunc(n);;
    return 1;
}
