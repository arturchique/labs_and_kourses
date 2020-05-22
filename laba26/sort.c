#include "sort.h"


void udtSort(List* list)
{	
	Iter k, kprev, tmp, tmpprev;
	k = first(list);
	int j;
	for (int i = 1; i < list->size; i++)
	{
		kprev = prev(&k);
		if (kprev.node->data.key > k.node->data.key)
		{
			tmp = k;
			tmpprev = kprev;
			j = i;
			while (tmpprev.node->data.key < tmp.node->data.key)
			{
				tmp = tmpprev;
				tmpprev = prev(&tmp);
				j--;
			}
			_delete(list, &k);
			k = search(list, j);
			insert(list, &k, tmp.node->data);
		}
	}
}