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
		printf("����\n");
		printf("1) �������� �������\n");
		printf("2) ������� �������\n");
		printf("3) ������ ������\n");
		printf("4) ����������\n");
		printf("5) ������\n");
		printf("6) �����\n");
		printf("�������� ��������: ");
		scanf("%d", &action);

		switch (action)
		{
		case 1:
		{
			printf("������� ����: ");
			scanf("%d", &item.data.key);
			printf("������� ������: ");
			getLine(item.data.value, sizeof(item.data.value));
			printf("������� �����, � ������� ����� �������� �������: )");
			scanf("%d", &place);

			if (insert(&udt, search(&udt, place), item.data))
				printf("������� � ������ %d � ������� '%s' �������� ������� �� %d �����\n", item.data.key, item.data.value, place);
			else
				printf("������ ��������\n");
		}
		break;

		case 2:
		{
			if (udt.size > 0)
			{
				printf("������� ������ ��������, ������� ����� �������: ");
				scanf("%d", &place);
				delete(&udt, search(&udt, place));

				printf("������� � ������ %d � ������� '%s' ������ �������\n", item.data.key, item.data.val);
			}
			else
				printf("������ ����\n");
		}
		break;

		case 3:
		{
			printf("������ ������: %d (�������� ������ ��� %d ���������)\n", udt.size, POOL_SIZE);
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
				printf("������:\n");

				printlist(&udt);
			}
			else
				printf("������ ����\n");
		}
		break;

		case 6: break;

		default:
		{
			printf("������. ������ ������ ���� �� ����������\n");
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