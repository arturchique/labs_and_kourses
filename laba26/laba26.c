#include <stdio.h>
#include "sort.h"
#include "sort.c"
#include "udt.h"
#include "udt.c"


void getLine(char* str, const int size);

int main(void)
{
	int action, place;
	char tmpCh;
	List udt;
	Item item;

	create(&udt);

	do
	{
		printf("Меню\n");
		printf("1) Добавить элемент\n");
		printf("2) Удалить элемент\n");
		printf("3) Размер списка\n");
		printf("4) Сортировка\n");
		printf("5) Печать\n");
		printf("6) Выход\n");
		printf("Выберите действие: ");
		scanf("%d", &action);

		switch (action)
		{
		case 1:
		{
			printf("Введите ключ: ");
			scanf("%d", &item.data.key);
			printf("Введите Строку: ");
			getLine(item.data.value, sizeof(item.data.value));
			printf("Введите место, в которое нужно вставить элемент: )");
			scanf("%d", &place);

			if (insert(&udt, search(&udt, place), item.data))
				printf("Элемент с ключом %d и строкой '%s' добавлен успешно на %d место\n", item.data.key, item.data.value, place);
			else
				printf("Список заполнен\n");
		}
		break;

		case 2:
		{
			if (udt.size > 0)
			{
				printf("Введите индекс элемента, который нужно удалить: ");
				scanf("%d", &place);
				delete(&udt, search(&udt, place));

				printf("Элемент с ключом %d и строкой '%s' удален успешно\n", item.data.key, item.data.val);
			}
			else
				printf("Список пуст\n");
		}
		break;

		case 3:
		{
			printf("Размер списка: %d (Выделено памяти под %d элементов)\n", udt.size, POOL_SIZE);
		}
		break;

		case 4:
		{
			sort(&udt);
		}
		break;

		case 5:
		{
			if (udt.size > 0)
			{
				printf("Список:\n");

				printlist(&udt);
			}
			else
				printf("Список пуст\n");
		}
		break;

		case 6: break;

		default:
		{
			printf("Ошибка. Такого пункта меню не существует\n");
		}
		break;
		}
	} while (action != 6);

	return 0;
}

void getLine(char* str, const int size)
{
	int cnt = 0, ch;

	while ((ch = getchar()) != '\n' && cnt < size - 1)
		str[cnt++] = ch;

	str[cnt] = '\0';
}