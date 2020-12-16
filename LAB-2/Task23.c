//Дана строка из нескольких слов. Слова отделяются друг от друга
//пробелами или запятыми. Подсчитать количество слов, 
//длина которых больше заданного числа.

#include <stdio.h>
#include <string.h>

int main()
{
	char string[100]; 
	int counter = 0;
	int wordLength = 0;
	int lastSymbol = 0; // Сохранение индекса начала слова
	int N = 0;
	printf("Please, input string: ");
	gets(string);
	printf("Please, input value: ");
	scanf_s("%d", &N);
	for (int i = 0; i <= strlen(string); i++) {
		if ((string[i] == ' ') || (string[i] == ',') || (string[i] == '\0'))
		{
			wordLength = i - lastSymbol;
			lastSymbol = i+1;
			if ((wordLength == 0) || (wordLength <= N)) { counter--; }
			counter++;
		}
	}
	printf("Count = %d", counter);
	return 0;
}
