/*2. Дан текст. Слова в тексте разделены пробелами и знаками препинания.
Получить n наиболее часто встречающихся слов и число их появлений.*/

#include <stdio.h>
#include <stdlib.h>

int memoryCounter(char* text) {
	int counter = 0, wordLength = 0, lastSymbol = 0;
	for (int i = 0; i < 256; i++) {
		if ((text[i] == ' ') || (text[i] == '.') || (text[i] == ',') || (text[i] == '!')) {
			wordLength = i - lastSymbol;
			if (wordLength == 0)
				counter--;
			counter++;
			lastSymbol = i + 1;
		}
	}
	counter++;
	return counter;
}

int main()
{
	int i, j, k, wordLength = 0, lastSymbol = 0;
	char buffer[256];
	printf("Please, input string: ");// Строки для отладки "I think that BSUIR is the best university in Belarus. BSUIR plays a big role for IT-Industy of our country!", "Nesvizh castle is a residental castle of radzivill family, castle was founded at 1551. It's really old!"
	rewind(stdin);
	gets(buffer);
	char** words = NULL;
	words = (char**)malloc(memoryCounter(buffer) * sizeof(char*));
	for (int i = 0; i < memoryCounter(buffer); i++) {
		words[i] = (char*)malloc(15 * sizeof(char));
	}
	int counter = 0;
	// Выделение слов в двумерный массив 
	for (i = 0; i < 256; i++) {
		if ((buffer[i] == ' ') || (buffer[i] == '.') || (buffer[i] == ',') || (buffer[i] == '!') || (buffer[i] == '\0')) {
			wordLength = i - lastSymbol;
			k = 0;
			for (j = lastSymbol; j <= i; j++) {
				if (j == i)
					words[counter][k] = ' ';
				words[counter][k] = buffer[j];
				k++;
			}
			if (wordLength == 0)
				counter--;
			counter++;
			lastSymbol = i + 1;
		}
	}
	// Поиск наиболее часто встречающегося слова
	int repeatCount = 0, maxRepeat = 0, maxIndex = 0, flag = 1;
	for (int j = 0; j < counter; j++)
	{
		for (int i = 0; i < counter; i++) {
			for (int k = 0; k < 15; k++)
			{
				if (words[j][k] != words[i][k])
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				repeatCount++;
			}
			flag = 1;
		}
		if (maxRepeat < repeatCount) {
			maxRepeat = repeatCount;
			maxIndex = j;
		}
		repeatCount = 0;
	}
	// Вывод информации
	int len = 0;
	for (i = 0; i < 15; i++) {
		if (words[maxIndex][i] == ' ')
			break;
		len++;
		
	}
	printf("The number of all words at text = %d", counter);
	printf("\nThe most common word - ");
	for (int i = 0; i < len; i++) {
		printf("%c", words[maxIndex][i]);
	}
	printf("\nIt was repeated %d times in text.", maxRepeat);
	return 0;
}