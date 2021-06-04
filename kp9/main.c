#include "KP9.h"

int main(void)
{
	const int N = 50;
	int i, cnt, action;
	char ch;
	Key keys[N];
	Val values[N];
	Key key;
	FILE *file = fopen("input.txt", "r");

	if (file == NULL)
	{
		printf("Ошибка при открытии файла\n");

		return 0;
	}

	i = 0;

	while (i < N && fscanf(file, "%d", &keys[i].key) == 1)
	{
		fscanf(file, "%c", &ch);
		getRow(file, values[i].val, sizeof(values[i].val));

		i++;
	}

	fclose(file);

	cnt = i;

	do
	{
		printf("Меню\n");
		printf("1) Печать\n");
		printf("2) Двоичный поиск\n");
		printf("3) Сортировка\n");
		printf("4) Перемешивание\n");
		printf("5) Реверс\n");
		printf("6) Выход\n");
		printf("Выберите действие\n");
		scanf("%d", &action);

		switch (action)
		{
			case 1:
			{
				printTable(keys, values, cnt);

				break;
			}

			case 2:
			{
				if (!isSorted(keys, cnt))
					printf("Ошибка. Таблица не отсортирована\n");
				else
				{
					printf("Введите ключ: ");
					scanf("%d", &key.key);

					i = binSearch(keys, values, cnt, key);

					if (i > -1)
						printf("Найдена строка: %s\n", values[i].val);
					else
						printf("Строка с таким ключом не найдена\n");
				}

				break;
			}

			case 3:
			{
				sort(keys, values, cnt);

				break;
			}

			case 4:
			{
				scramble(keys, values, cnt);

				break;
			}

			case 5:
			{
				reverse(keys, values, cnt);

				break;
			}

			case 6: break;

			default:
			{
				printf("Ошибка. Такого пункта меню не существует\n");

				break;
			}
		}
	}
	while (action != 6);

	return 0;
}

