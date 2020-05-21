#include "sort.h"


void udtSort(List* list)
{	
	int j;
	Iter k;
	Item tmp;
	for (int i = 1; i < list->size; i++)
	{
		if (list->item[i].data.key > list->item[i-1].data.key)
		{
			tmp = list->item[i];
			delete(list, i);
			j = i;
			while (tmp.data.key > list->item[j-1].data.key)
			{
				j--;
			}
			k = search(list, j);
			insert(list, k, tmp.data)
		}
	}
}