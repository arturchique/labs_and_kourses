#include <stdio.h>
#include "spisok.h"

void udt_create(list *s){
	int i;
	for (i = 0; i < 9; i++)
		s->mas[i].next = i + 1;
	s->mas[9].next = -1;
	s->first = -1;
	s->free = 0;
	s->size = 0;
}

int udt_is_empty(const list *s) {
	return s->size == 0;
}

void udt_print(const list *s) {
	int t;
	if (s->size == 0) printf("spisok empty\n");
	else {
		printf(" key value\n");
		t =s->first;
		while (t != -1) {
			printf(" %d     %c\n", s->mas[t].key, s->mas[t].value);
			t = s->mas[t].next;
		}
	}
}

int udt_size(const list *s) {
	return s->size;
}

void udt_insert(list *s, const data_type el, int nm) {
	int k,n,t;
	if (s->size == 10) printf("not space\n");
	else if (nm > s->size + 1) printf("error number\n");
	else {
		s->size++;
		k = s->free;
		s->free = s->mas[s->free].next;
		s->mas[k] = el;
		if (nm == 1) {
			s->mas[k].next = s->first;
			s->first = k;
		}
		else {
			t = s->first;
			for (n = 1; n < nm - 1; n++)
				t = s->mas[t].next;
			s->mas[k].next = s->mas[t].next;
			s->mas[t].next = k;
		}
	}
}

data_type udt_erase(list *s, int nm) {
	int k,n,t;
	if (s->size == 0) printf("spisok empty\n");
	else if(nm>s->size) printf("error number\n");
	else {
		 s->size--;
		 if (nm == 1) {
			 t = s->first;
			 s->first = s->mas[t].next;
			 s->mas[t].next = s->free;
			 s->free = t;
		 }
		else {
			 k = s->first;
			 for (n = 1; n < nm - 1; n++)
				 k = s->mas[k].next;
			 t = s->mas[k].next;
			 s->mas[k].next = s->mas[t].next;
			 s->mas[t].next = s->free;
			 s->free = t;
		}
		 return s->mas[t];
	}

	   
}