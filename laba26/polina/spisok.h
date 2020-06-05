#ifndef _UDT_H_
#define _UDT_H_

typedef int key_type;
typedef char value_type;
	
typedef struct {
  key_type key;
  value_type value;
  int next;
} data_type;

typedef struct {	
   data_type mas[10];
   int first,free;
   int size;

} list;
 
void udt_create(list *); 
int udt_is_empty(const list *); 
void udt_print(const list *); 
int udt_size(const list *);
void udt_insert(list *, const data_type, int); 
data_type udt_erase(list *,int);

#endif














































