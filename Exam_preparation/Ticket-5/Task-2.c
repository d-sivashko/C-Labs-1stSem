// Билет 5 - Задача 2. Ввести с клавиатуры 2 строки, большую строку вставить в меньшую начиная с позиции n (n - с клавиатуры). Третью строку не создавать!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_len(char* text) {
    int i = 0, len = 0;
    while (text[i] != '\0') {
        i++; len++;
    }
    return (len);
}

char* str_insert(char* longStr, const char* shortStr, int pos) {
    char* tmp = longStr;
    char* sa, * sb, * end;
    for (end = longStr; *end; end++);
    for (longStr += pos; *shortStr; *longStr++ = *shortStr++, ++end)
        for (sa = end + 1, sb = end; sa > longStr; *sa-- = *sb--);
    return tmp;
}

int main() {
    int n = 0, size1 = 0, size2 = 0;
    char str1[128], str2[128];
    printf("Input 1-st string: ");
    gets(str1);
    printf("Input 2-nd string: ");
    gets(str2);
    printf("Input n: ");
    scanf_s("%d", &n);
    printf("Inserted: ");
    if (str_len(str1) >= str_len(str2)) {
        str_insert(str1, str2, n);
        puts(str1);
    }
    else {
        str_insert(str2, str1, n);
        puts(str2);
    }
    return 0;
}
