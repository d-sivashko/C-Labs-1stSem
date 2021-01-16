#include <stdio.h>
#include <stdlib.h>

#define N 10

// tmp - temporary file(временная файл/память для хранения переменной)

void Display(int size, int* array); // Функция отображения массива

void Selection_Sort(int size, int* array) // "Через отбор"
{
	int i, j, SortIndex, tmp;
	for (i = 0; i < size; i++)
	{
		SortIndex = i;                       // индекс элемента для упорядочивания
		tmp = array[i];                     // значение элемента во временную переменную
		for (j = i + 1; j < size; j++)     // перебор последующих эл-тов справа от i-го
			if (array[j] < tmp)           // ecли найден меньший
			{
				SortIndex = j;          // запоминаем его индекс и значение
				tmp = array[j];
			}
		array[SortIndex] = array[i];  // заменяем выбранный и меньший
		array[i] = tmp;
	}
}

void Paste_Sort(int size, int* array) // "Вставками"
{
	int i, j, tmp;
	for (i = 1; i < size; i++)              // индекс элемента для упорядочивания
	{
		j = i - 1;                        // !индекс предыдущего элемента
		tmp = array[i];                  // значение предыдущего элемента
		while (j >= 0 && tmp < array[j])
			array[j-- + 1] = array[j]; // сдвиг всех элементов направо
		array[j + 1] = tmp;           // запись в освободившийся или в тот же элемент
	}
}

void Bubble_Sort(int size, int* array) // "Пузырёк"
{
	int i, j, tmp;
	for(i = 0; i < size - 1; i++)          // цикл выбора эл-тов до последнего к упорядочиванию
		for (j = size - 1; j > i; j--)    // цикл перебора эл-тов с конечного до i-го
			if (array[j -1] > array[j])  // если (j-1)-й > j-го элемента, то выполняем перестановку
			{
				tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
			}
}

void Shaker_Sort(int size, int* array) // "Шейкер/Коктейль"
{
	int left = 0, right = size - 1;                                // левая и правая границы сортируемой области массива
	int flag = 1, tmp;                                            // флаг наличия перемещений и инициализация временной переменной
	while ((left < right) && flag > 0)                           // Выполнение цикла пока левая граница не сомкнётся с правой и пока в массиве имеются перемещения
	{
		flag = 0;
		for (int i = left; i < right; i++)                     // двигаемся слева направо
		{
			if (array[i] > array[i + 1])                     // если следующий элемент меньше текущего,
			{                                               // меняем их местами
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				flag = 1;                                // перемещения в этом цикле были
			}
		}
		right--;                                       // сдвигаем правую границу на предыдущий элемент
		for (int i = right; i > left; i--)            // двигаемся справа налево
		{
			if (array[i - 1] > array[i])            // если предыдущий элемент больше текущего,
			{                                      // меняем их местами
				tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp;
				flag = 1;                       // перемещения в этом цикле были
			}
		}
		left++;                               // сдвигаем левую границу на следующий элемент
	}
}

void Shell_Sort(int size,int* array) // "Метод Шелла"
{
	int i, j, step, tmp;
	for(step = size/2; step > 0; step /= 2)										// Выбор шага
		for(i = step; i < size; i++)										   // Перечисление элементов, которые сортируются на определённом шаге
			for (j = i - step; j >= 0 && array[j] > array[j+step]; j-= step)  // Перестановка элементов внутри подсписка, пока i-тый не будет отсортирован
			{
				tmp = array[j];
				array[j] = array[j + step];
				array[j+step] = tmp;
			}
}

int main()
{
	int array[N] = { 5,9,3,7,8,2,10,6,1,4 };
	printf("Array before sort: ");
	Display(N, array);
	printf("\n\nChoose way of sort\n");
	printf("1. Selection_Sort\n");
	printf("2. Paste_Sort\n");
	printf("3. Bubble_Sort \n");
	printf("4. Shaker_Sort\n");
	printf("5. Shell_Sort \n");
	printf("Your choice? ");
	int input;
	scanf_s("%d", &input);
	switch (input) // Выбор метода сортировки
	{
	case 1:            
		Selection_Sort(N, array);
		break;
	case 2:
		Paste_Sort(N, array);
		break;
	case 3:
		Bubble_Sort(N, array);
		break;
	case 4:
		Shaker_Sort(N, array);
		break;
	case 5:
		Shell_Sort(N, array);
		break;
	default:
		printf("Error!\n"); return 1;
	}
	printf("\nArray after sort: ");
	Display(N, array);
	return 0;
}

void Display(int size, int* array) // Для отображения массива
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}
