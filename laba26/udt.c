#include "udt.h"

int equal(Iter* lhs, Iter* rhs)
{
	return lhs->node == rhs->node;
}

Iter next(Iter* i)
{
	i->node = i->node->next;
	return *i;
}

Iter prev(Iter* i)
{
	i->node = i->node->prev;
	return *i;
}

Data fetch(Iter* i)
{
	return i->node->data;
}

void store(Iter* i, Data t)
{
	i->node->data = t;
}

void create(List* l)
{
	int i;
	for (i = 0; i < POOL_SIZE; i++)
		l->item[i].next = &(l->item[i + 1]);
	l->item[POOL_SIZE - 1].next = 0;
	l->head = &(l->item[POOL_SIZE]);
	l->head->prev = l->head->next = l->head;
	l->top = &(l->item[0]);
	l->size = 0;
}

Iter last(List* l) 
{
	Iter res;
	res.node = l->head;
	return res;
}

Iter first(List* l)
{
	Iter res;
	res.node = l->head->next;
	return res;
}

Iter insert(List* l, Iter* i, Data t)
{
	Iter res;
	res.node= l->top;
	if (!res.node)
		return last(l);
	l->top = l->top->next;
	res.node->data = t;
	res.node->next = i->node;
	res.node->prev = i->node->prev;
	res.node->prev->next = res.node;
	i->node->prev = res.node;
	l->size++;
	return res;
}

Iter _delete(List* l, Iter* i)
{
	Iter res = last(l);
	if (equal(i, &res))
		return res;
	res.node = i->node->next;
	res.node->prev = i->node->prev;
	i->node->prev->next = res.node;
	l->size--;
	i->node->next = l->top;
	l->top = i->node;
	i->node = 0;
	return res;

}

Iter search(List* l, int i)
{
	int j = 0;
	Iter res = first(l);
	while (j<i)
	{
		res = next(&res);
	}
	return res;
}

void printlist(List* l) 
{
	int i;
	Iter k;
	k = first(l);
	while (i < l->size)
	{
		printf("%d) %d %s", i, k.node->data.key, k.node->data.value);
		k = next(&k);
		i++;
	}
}

