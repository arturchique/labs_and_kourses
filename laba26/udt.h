#ifndef UDT_H
#define UDT_H

#include <stdio.h>
#include <stdlib.h>


// Структура

const int POOL_SIZE = 40;


typedef struct _Data
{
	int key;
	char value[20];
} Data;


typedef struct _Item
{
	Data data;
	struct _Item* prev;
	struct _Item* next;
} Item;


typedef struct _Iter
{
	Item* node;
} Iter;


typedef struct _List
{
	Item* head;
	int size;
	Item* top;
	Item item[POOL_SIZE + 1];

} List;


// Функции

Iter _delete(List* l, Iter* i);
Iter first(List* l);
Iter insert(List* l, Iter* i, Data t);
Iter last(List* l);
void create(List* l);
void store(Iter* i, Data t);
Data fetch(Iter* i);
Iter prev(Iter* i);
Iter next(Iter* i);
int equal(Iter* lhs, Iter* rhs);
Iter search(List* l, int i);
Iter first(List* l);
void printlist(List* l);

#endif