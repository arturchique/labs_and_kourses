#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tree
{
    int key;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
} node;


node *create(node *root, int key)
{
    node *tmp = malloc(sizeof(node));
    tmp -> key = key;
    tmp -> parent = NULL;
    tmp -> left = tmp -> right = NULL;
    root = tmp;
    return root;
}


node *add(node *root, int key)
{
    node *root2 = root, *root3 = NULL;
    node *tmp = malloc(sizeof(node));
    tmp -> key = key;
    while (root2 != NULL)
    {
        root3 = root2;
        if (key < root2 -> key)
            root2 = root2 -> left;
        else
            root2 = root2 -> right;
    }
    tmp -> parent = root3;
    tmp -> left = NULL;
    tmp -> right = NULL;
    if (key < root3 -> key) root3 -> left = tmp;
    else root3 -> right = tmp;
    return root;
}


node *search(node * root, int key)
{
    if ((root == NULL) || (root -> key == key))
        return root;
    if (key < root -> key)
        return search(root -> left, key);
    else return search(root -> right, key);
}


node *min(node *root)
{
    node *l = root;
    while (l -> left != NULL)
        l = l -> left;
    return l;
}


node *max(node *root)
{
    node *r = root;
    while (r -> right != NULL)
        r = r -> right;
    return r;
}


node *succ(node *root)
{
    node *p = root, *l = NULL;
    if (p -> right != NULL)
        return min(p -> right);
    l = p -> parent;
    while ((l != NULL) && (p == l -> right))
    {
        p = l;
        l = l -> parent;
    }
    return l;
}


node *delete(node *root, int key)
{
    node *p = root, *l = NULL, *m = NULL;
    l = search(root, key);
    if ((l -> left == NULL) && (l -> right == NULL))
    {
        m = l -> parent;
        if (l == m -> right) m -> right == NULL;
        else m -> left == NULL;
        free(l);
    }
    if ((l -> left == NULL) && (l -> right != NULL))
    {
        m = l -> parent;
        if (l == m -> right) m -> right == l -> right;
        else m -> left == l -> right;
        free(l);
    }
    if ((l -> left != NULL) && (l -> right == NULL))
    {
        m = l -> parent;
        if (l == m -> right) m -> right == l -> left;
        else m -> left == l -> left;
        free(l);
    }
    if ((l -> left != NULL) && (l -> right != NULL))
    {
        m = succ(l);
        l -> key = m -> key;
        if (m -> right == NULL)
            m -> parent -> left = NULL;
        else m -> parent -> left = m -> right;
        free(m);
    }
    return root;
}


void preorder(node *root)
{
    if (root == NULL)
        return;
    if (root -> key)
        printf("%d ", root -> key);
    preorder(root -> left);
    preorder(root -> right);
}


void showtree (node *root, int n) { 
  if (root->left) showtree(root->left, n+1); 
  for (int i = 0; i < n; i++) printf("  "); 
  printf("%d\n", root->key); 
  if (root->right) showtree(root->right, n+1); 
}


void check(node *root, int a, int b, int flag)
{
    if (!root) return;
	check(root->left, a, b, flag);
	if((root->left == NULL) && (root->right == NULL)){
	    if ((root->key < a) || (root->key > b)){
		    flag = 0;
	    }    
	}
	check(root->right, a, b, flag);
}


int main(int argc, char const *argv[])
{
	node *root;
	int key, result, a, b;

	for(;;)
	{	
		char answer[20];
		printf("\n   Выберите действие, которое нужно выполнить с деревом:\n\n\t-Чтобы создать дерево, введите 'create'\n\t-Чтобы добавить узел дереву, введите 'add'\n\t-Чтобы удалить узел дерева, введите 'delete'\n\t-Чтобы вывести содержимое дерева, введите 'show'\n\t-Чтобы проверить, находятся ли во всех листьях двоичного дерева элементы со значениями в заданном диапазоне, введите 'find'\n\t-Чтобы закончить работу программы, введите 'end'\n\n >> ");
		scanf("%s", answer);

		if (strcmp(answer, "end") == 0){
			printf("Конец работы программы");
			break;
		} else if(strcmp(answer, "create") == 0){
			printf("\n   Введите значение корня\n\n >> ");
			scanf("%d", &key);
			root = create(root, key);
			printf("\n   Дерево успешно создано\n");
		} else if(strcmp(answer, "show") == 0){
			printf("\n");
			showtree(root, 0);
			printf("\n");
		} else if(strcmp(answer, "add") == 0){
			printf("\n   Введите значение узла\n\n >> ");
			scanf("%d", &key);
			root = add(root, key);
			printf("\n   Узел успешно добавлен\n");
		} else if(strcmp(answer, "delete") == 0){
			printf("\n   Введите значение узла, который нужно удалить\n\n >> ");
			scanf("%d", &key);
			root = delete(root, key);
			printf("\n   Узел успешно удален\n");

		} else if(strcmp(answer, "find") == 0){
			printf("\n   Введите значения отрезка\n\n >> ");
			scanf("%d", &a);
			scanf("%d", &b);
			int flag = 1;
			check(root, a, b, flag);
			if (flag == 1)
			{
				printf("Листья, действительно попадают в заданный диапазон значений\n");
			} else{
				printf("Значения листьев дерева выходит за границы заданного значения\n");
			}
		}

	}

	return 0;
}
