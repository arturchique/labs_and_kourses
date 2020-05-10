#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Структура
typedef struct _item{
	char data[20];
	struct _item* prev;
	struct _item* next;
} Item;

typedef struct{
	Item* node;
} Iterator;

typedef struct {
	Item* head;
	int size;
} List;


// Функции над элементами и итераторами списка
bool equal(const Iterator* lhs, const Iterator* rhs){
	return lhs->node == rhs->node;
}

Iterator next(Iterator* i){
	i->node = i->node->next;
	return *i;
}

Iterator prev(Iterator* i){
	i->node = i->node->prev;
	return *i;
}

char* fetch(const Iterator* i){
	return i->node->data;
}

/*void store(const Iterator* i, const char t){
	i->node->data = t;
}*/

void create(List* l){
	l-> head = NULL;
	l->head->next = NULL;
	l->head->prev = NULL;
	l->size = 0;
}

Iterator* search(const List* l, const int* num){
	int j = 1;
	Iterator i;
	i.node = l->head;
	while(j < *num){
		next(&i);
		j++;
	}
	return &i;
}

Iterator get_last(List* l){
	Iterator i;
	i.node = l->head;
	while(i.node->next){
		i = next(&i);
	}
	return i;
}

void print_list(const List* l){
	int k = 0;
	if(l->head == NULL){
		printf("Список пуст\n");
		return;
	}
	Iterator i;
	i.node = l->head;
	while(i.node->next){
		k++;
		printf("%d  |  %s\n", k, fetch(&i));
	}
	k++;
	printf("%d  |  %s\n", k, fetch(&i));
}

void insert(List* l, Iterator* i, const char t[20]){
	Iterator res;
	res.node = (Item *) malloc(sizeof(Item));
	Iterator h;
	h.node = l->head;
	if(l->head == 0){
		printf("Список пуст\nДобавляемый элемент будет первым\n");
		l->head = (Item *) malloc(sizeof(Item));
		strcpy(l->head->data, t);
		l->head->next = NULL;
		l->head->prev = NULL;
		l->size++;
		return;
	} else if(equal(i, &h)){
		strcpy(res.node->data, t);
		res.node->next = l->head;
		res.node->prev = NULL;
		l->head->prev = res.node;
		l->size++;
		return;
	} else{
		strcpy(res.node->data, t);
		res.node->next = i->node;
		res.node->prev = i->node->prev;
		res.node->prev->next = res.node;
		i->node->prev = res.node;
		l->size++;
		return;
	}
}

int main()
{
	List* list;
	char t[20];
	create(list);
	int len;
	printf("Введите длину списка\n");
	scanf("%d", len);
	printf("Введите список\n");
	for (int i = 0; i < len; ++i){
		scanf("%s", t);
		insert(list, search(list, &i), t);
	}

	print_list(list);
	return 0;
}