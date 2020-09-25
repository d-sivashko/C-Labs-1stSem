#include <stdio.h>

int main()
{
	int n = 0;
	int countplus = 0; 
	int countminus = 0;
	int countzero = 0;
	int summplus = 0; 
	int summminus = 0;
	printf("Please, input count: ");
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
			int c = 0;
			printf("Please, input number: ");
			scanf_s("%d", &c);
			if (c > 0)
			{
				countplus++;
				summplus = summplus + c;
			}
			else if (c < 0)
			{
				countminus++;
				summminus = summminus + c;
			}
			else
			{
				countzero++;
			}

	}
	printf("Summplus = %d\n", summplus);
	printf("Summminus = %d\n", summminus);
	printf("Value plus = %d\n", countplus);
	printf("Value minus = %d\n", countminus);
	printf("Value zero = %d\n", countzero);
	return 0;
}