#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

int main()
{
	//setlocale(LC_ALL, "Rus");
	char string[100]; 
	
	printf("Please, input string: ");
	gets(string);
	printf("String: ");
	puts(string);
	int counter = 0;
	int wordLength = 0;
	int lastSymbol = 0; // Сохранение индекса начала слова
	int N = 0;
	printf("\nPlease, input value: ");
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
	
	printf("Count = %d\n", counter);
	return 0;
}