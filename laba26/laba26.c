#include <stdio.h>
#include "sort.h"
#include "sort.c"
#include "udt.h"
#include "udt.c"


void getLine(char* str, const int size);

int main(void)
{
	const int N = 10;
	int action;
	char tmpCh;
	Udt udt;
	Item item;

	udtCreate(&udt, N);

	do
	{
		printf("����\n");
		printf("1) �������� �������\n");
		printf("2) ������� �������\n");
		printf("3) ������ �������\n");
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
			scanf("%lf", &item._key);
			scanf("%c", &tmpCh);
			printf("������� ������: ");
			getLine(item._val, sizeof(item._val));

			if (udtPush(&udt, item))
				printf("������� � ������ %lf � ������� '%s' �������� �������\n", item._key, item._val);
			else
				printf("������� ���������\n");
		}
		break;

		case 2:
		{
			if (udtSize(&udt) > 0)
			{
				item = udtFront(&udt);

				udtPop(&udt);

				printf("������� � ������ %lf � ������� '%s' ������ �������\n", item._key, item._val);
			}
			else
				printf("������� �����\n");
		}
		break;

		case 3:
		{
			printf("������ �������: %d (�������� ������: %d)\n", udtSize(&udt), N);
		}
		break;

		case 4:
		{
			udtSort(&udt);
		}
		break;

		case 5:
		{
			if (udtSize(&udt) > 0)
			{
				printf("�������:\n");

				udtPrint(&udt);
			}
			else
				printf("������� ����\n");
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

	udtDestroy(&udt);

	return 0;
}

void getLine(char* str, const int size)
{
	int cnt = 0, ch;

	while ((ch = getchar()) != '\n' && cnt < size - 1)
		str[cnt++] = ch;

	str[cnt] = '\0';
}