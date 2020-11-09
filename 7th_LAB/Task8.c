/*8. Даны натуральное число n и символы s1,…,sn. Группы символов,
разделенные пробелами (одним или несколькими) и не содержащими пробелов внутри себя, будем называть словами:
а) подсчитать количество слов в данной последовательности;
б) преобразовать данную последовательность,
заменяя всякое вхождение слова str1 длинной n, на слова str2 длинной m.*/


#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main()
{
	char* str = NULL;
	int i, n = 0, wordLength = 0, lastSymbol = 0, wordCount = 0;
	do
	{
		system("CLS");
		fflush(stdin);
		printf("Please, input size of n: ");
	} while (!scanf("%d", &n) || n <= 0);
	if (!(str = (char*)calloc(n, sizeof(char))))
	{
		printf("\nNot enough free memory!\n");
		return 0;
	}
	printf("Please, input string: "); 
	gets(str);
	fflush(stdin);
	gets(str);
	//условие а)
	for (i = 0; i < n; i++)
	{
		if ((str[i] == ' ') || str[i] == '\0') {
			wordLength = i - lastSymbol;
			lastSymbol = i + 1;
			if (wordLength == 0)
				wordCount--;
			wordCount++;
		}
	}
	printf("WordCount = %d\n", wordCount);
	// Условие б)
	char freeStr[256] = "", * pstr = str, *pfreeStr = freeStr, oldWord[10] = "", newWord[10] = "";
	printf("\nOld String: ");
	puts(str);
	printf("Input word, you want change: ");
	gets(oldWord);
	printf("Input new word: ");
	gets(newWord);
	//цикл замены 
	const size_t oldWordSize = strlen(oldWord), newWordSize = strlen(newWord);
	for (; *pfreeStr = *pstr; ++pstr, ++pfreeStr) 
	{
		if (!strncmp(pstr, oldWord, oldWordSize)) {
			strcpy(pfreeStr, newWord);
			pstr += oldWordSize - 1;
			pfreeStr += newWordSize - 1;
		}
	}
	printf("New string: ");
	puts(freeStr);
	free(str);
	return 0;
}


