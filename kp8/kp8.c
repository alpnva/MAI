#include <stdio.h>
#include "list.h"

int main(void)
{
	const int N = 10;
	int i, isFound, action, pos;
	char arg;
	List list;
	Iterator it;
	int k, n;
	char rubish;

	listCreate(&list, N);

	do
	{
		printf("Меню:\n");
		printf("1) Вставить элемент\n");
		printf("2) Удалить элемент\n");
		printf("3) Печать списка\n");
		printf("4) Подсчет длины списка\n");
		printf("5) Выполнить задание над списком\n");
		printf("6) Выход\n");
		printf("Выберите действие: ");
		scanf("%d", &action);

		switch (action)
		{
		case 1:
		{
			printf("Введите позицию элемента: ");
			scanf("%d", &pos);
			scanf("%c", &rubish);
			printf("Введите значение элемента: ");
			scanf("%c", &arg);
			listInsert(&list, pos - 1, arg);

			break;
		}

		case 2:
		{
			printf("Введите номер элемента: ");
			scanf("%d", &pos);

			listRemove(&list, pos - 1);

			break;
		}

		case 3:
		{
			if (listEmpty(&list))
				printf("Список пуст\n");
			else
				listPrint(&list);

			break;
		}

		case 4:
		{
			printf("Длина списка: %d\n", listSize(&list));

			break;
		}

		case 5:
		{
			printf("Введите k:\n");
			scanf("%d", &k);
			if (k > listSize(&list)) printf("Введённое значение больше, чем текущий размер списка!\n");
			else {
				for (int j = 0; j < k; j++) {
					n = listSize(&list);
					listRemove(&list, n / 2);
				}
			}

			break;
		}

		case 6: break;

		default:
		{
			printf("Ошибка. Такого пункта меню не существует\n");

			break;
		}
		}
	} while (action != 6);

	listDestroy(&list);

	return 0;
}

