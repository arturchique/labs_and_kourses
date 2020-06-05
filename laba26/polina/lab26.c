#include <stdio.h>
#include "spisok.h"

int change(list *s) {
	int i,k;
		data_type t, z;
		k = udt_size(s);
		t = udt_erase(s, 1);
		for (i = 1; i < k; i++) {
			z = udt_erase(s, i);
				if (t.key <= z.key) {
					udt_insert(s, t, i);
					t = z;
				}
				else {
					udt_insert(s, z, i);
					udt_insert(s, t, i+1);
					return 1;
				}
		}
		udt_insert(s, t, i);
		return 0;
}

void sort(list *s) {
	while (change(s) == 1);
}

int main()
{
 data_type el;
 list s;
 int menu=0,nm;
 udt_create(&s);
  while(menu!=6) {
      printf(" 1.print, 2.add, 3.delete, 4.razmer, 5.sort, 6.end\n==>  ");
        scanf("%d",&menu);   
        switch(menu){
		  case 1: udt_print(&s);
                          break;
		  case 2: printf("vvedite key(int),value(char): ");
			  scanf("%d%c", &el.key, &el.value);
			  printf("vvedite nomer el: ");
			  scanf("%d", &nm);
			  udt_insert(&s, el, nm);
                          break;
		  case 3: printf("vvedite nomer el: ");
			  scanf("%d", &nm);
			  udt_erase(&s, nm);
                          break;
		  case 4: printf("size=%d\n", udt_size(&s));
			  break;
		  case 5: if(udt_size(&s)>1) sort(&s);
			  break;
        }
   }
}
