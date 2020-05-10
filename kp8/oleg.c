#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ИТЕРАТОРЫ
typedef struct item
{
char data[20];
struct item* prev;
struct item* next;
}item;
typedef struct
{
item* node;
} iterator;
//ПЕРЕМЕЩЕНИЕ ПО СПИСКУ
//СЛЕДУЮЩИЙ ЭЛЕМЕНТ
iterator next(iterator* i)
{
i->node = i->node->next;
return *i;
}
//ПРЕДЫДУЩИЙ ЭЛЕМЕНТ
iterator prev(iterator* i)
{
i->node = i->node->prev;
return *i;
}
//ЧТЕНИЕ ЭЛЕМЕНТА СПИСКА
char* fetch(const iterator* i)
{
return i->node->data;
}
//СРАВНЕНИЕ ИТЕРАТОРОВ
int equal(const iterator* lhs, const iterator* rhs)
{
return lhs->node == rhs->node;
}
//РЕАЛИЗАЦИЯ СПИСКА
typedef struct
{
item* head;
int size;
}list;
//СОЗДАНИЕ СПИСКА
void create(list* l)
{
l->head = 0;
l->size = 0;
}
iterator search(const list* l, const int* num)
{
int j = 1;
iterator i;
i.node = l->head;
while (j < *num)
{
next(&i);
j++;
}
return i;
}
//ПОЛУЧЕНИЕ ИТЕРАТОРА ПОСЛЕДНЕГО ЭЛЕМЕНТА
iterator get_last(list* l)
{
iterator i;
i.node = l->head;
while (i.node->next)
{
i = next(&i);
}
return i;
}
//ПЕЧАТЬ СПИСКА
void print_list(const list *l)
{
int k = 0;
//ПРОВЕРКА НА ПУСТОТУ СПИСКА
if (l->head == 0)
{
printf("Список пустой\n");
return;
}
//СОЗДАНИЕ ИТЕРАТОРА ДЛЯ ГОЛОВЫ СПИСКА
iterator i;
i.node = l->head;
//ПЕЧАТЬ ЕСЛИ ИТЕРАТОР СЛЕДУЮЩЕГО ЭЛЕМЕНТА НЕ НОЛЬ
while(i.node->next)
{
k++;
printf("%d | %s\n", k, fetch(&i));
//ПОЛУЧЕНИЕ СЛЕДУЮЩЕГО ЭЛЕМЕНТА
i = next(&i);
}
//ПЕЧАТЬ ПОСЛЕДНЕГО ЭЛЕМЕНТА
k++;
printf("%d | %s\n", k, fetch(&i));
}
//ВСТАВКА
void insert(list* l, iterator* i, const char t[20])
{
//СОЗДАНИЕ ИТЕРАТОРА
iterator res;
res.node = (item*) malloc(sizeof(item));
//ПОЛУЧЕНИЕ ИТЕРАТОРА ГОЛОВЫ СПИСКА
iterator h;
h.node = l->head;
//ЕСЛИ СПИСОК ПУСТ
if (l->head == 0)
{
printf("Список пуст\nДобавляемый элемент будет первым\n");
l->head = (item*) malloc(sizeof(item));
strcpy(l->head->data, t);
l->head->next = 0;
l->head->prev = 0;
l->size++;
return;
}
//ЕСЛИ НОМЕР ИТЕРАТОРА "1"
if (equal(i, &h))
{
strcpy(res.node->data, t);
res.node->next = l->head;
res.node->prev = 0;
l->head->prev = res.node;
l->head = res.node;
l->size++;
return;
}
//В ОСТАЛЬНЫХ СЛУЧАЯХ
strcpy(res.node->data, t);
res.node->next = i->node;
res.node->prev = i->node->prev;
res.node->prev->next = res.node;
i->node->prev = res.node;
l->size++;
return;
}
//УДАЛЕНИЕ
void _delete(list *l, iterator* i)
{
//ПОЛУЧЕНИЕ ИТЕРАТОРА ГОЛОВЫ СПИСКА
iterator h;
h.node = l->head;
//ЕСЛИ СПИСОК ПУСТОЙ
if (l->head == 0)
{
printf("Список пустой\n");
return;
}
//ЕСЛИ НОМЕР ИТЕРАТОРА "1"
if (equal(i, &h))
{
item* i;
i = l->head->next;
l->head->next = 0;
free(l->head);
l->head = i;
l->size--;
return;
}
//ЕСЛИ ИТЕРАТОР ПОСЛЕДНЕГО ЭЛЕМЕНТА
if (i->node->next == 0)
{
i->node->prev->next = i->node->next;
l->size--;
free(i->node);
i->node = 0;
return;
}
i->node->prev->next= i->node->next;
i->node->next->prev = i->node->prev;
i->node->next = i->node->prev = 0;
l->size--;
free(i->node);
i->node = 0;
}
//ПОДСЧЕТ ДЛИНЫ СПИСКА
int size(const list* l)
{
return l->size;
}
//ДОБАВЛЕНИЕ k ЭКЗЕМПЛЯРОВ ПОСЛЕДНЕГО ЭЛЕМЕНТА В НАЧАЛО СПИСКА
void add(list *l, int* k)
{
//ПОЛУЧЕНИЕ ИТЕРАТОРА ПОСЛЕДНЕГО ЭЛЕМЕНТА СПИСКА
iterator last = get_last(l);
//ПОЛУЧЕНИЕ ИТЕРАТОРА ГОЛОВЫ СПИСКА
iterator h;
h.node = l->head;
//ВСТАВКА ПОСЛЕДНЕГО ЭЛЕМЕНТА ПЕРЕД ПЕРВЫМ k РАЗ
while (*k > 0)
{
insert(l, &h, last.node->data);
(*k)--;
}
}
//MAIN
int main()
{
//СОЗДАНИЕ СПИСКА
list l;
create(&l);
//МЕНЮ
//ПЕЧАТЬ МЕНЮ
printf("Введите число:\n");
printf("\"1\" - печать списка\n");
printf("\"2\" - вставка нового элемента в список\n");
printf("\"3\" - удаление элемента из списка\n");
printf("\"4\" - подсчет длины списка\n");
printf("\"5\" - добавить указанное число экземпляров последнего элемента в начало списка\n");
printf("\"6\" - выход\n");
char menu = 0;
char t[20];
int num;
iterator i;
//СЧИТЫВАНИЕ ЧИСЛА С ПРОВЕРКОЙ (ВЫБОР ПУНКТА)
while (menu != 54)
{
do
{
scanf("%c", &menu);
} while (menu < 49 || menu > 54);
//ПУНКТЫ МЕНЮ
switch (menu)
{
case '1':
print_list(&l);
break;
case '2':
//ВВОД ДАННЫХ
printf("Введите строку, которую хотите добавить: ");
scanf("%s", t);
printf("Номер элемента, перед которым хотите добавить данные: ");
scanf("%d", &num);
//ПОИСК ИТЕРАТОРА ЭЛЕМЕНТА С ТАКИМ НОМЕРОМ
i = search(&l, &num);
//ВЫЗОВ ФУНКЦИИ
insert(&l, &i, t);
break;
case '3':
//ВВОД ДАННЫХ
printf("Введите элемент, который хотите удалить: ");
scanf("%d", &num);
//ПОИСК ИТЕРАТОРА ЭЛЕМЕНТА С ТАКИМ НОМЕРОМ
i = search(&l, &num);
//ВЫЗОВ ФУНКЦИИ
_delete(&l, &i);
break;
case '4':
//ВЫЗОВ ФУНКЦИИ
printf("Длина списка: %d\n", size(&l));
break;
case '5':
//ВВОД ДАННЫХ
printf("Введите количество экземпляров: ");
scanf("%d", &num);
//ВЫЗОВ ФУНКЦИИ
add(&l, &num);
break;
}
}
return 0;
}