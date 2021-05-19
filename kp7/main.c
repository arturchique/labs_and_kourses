#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h> 

// структура матрицы
struct _node_col{
	int column;
	double element;
	struct _node_col *next;
};

typedef struct _node_col Node_col;

//ряд (ссылка на первый элемент и на следующий)
struct _node_row{
	Node_col *begin_row;
	struct _node_row *next;
	
};

typedef struct _node_row Node_row;

//структура матрицы (ее размеры и ссылка на первый элемент)
struct _matrix{
	int n;
	int m;
	int entries;
	Node_row *head_row;
};

typedef struct _matrix *Matrix;

// функции над структурой

//создаём столбец
Node_col *node_col_create(){
	Node_col *new_node = (Node_col *) calloc(1, sizeof(Node_col));
	if(new_node == NULL){
		printf("Ошибка. Не хватает памяти\n");
		exit(1);
	}
	new_node->next = NULL;
	return new_node;
}

//создаём ряд (выделяем память)
Node_row *node_row_create(){
	Node_row *new_node = (Node_row *) calloc(1, sizeof(Node_row));
	if(new_node == NULL){
		printf("Ошибка. Не хватает памяти\n");
		exit(1);
	}
	new_node->begin_row = NULL;
	new_node->next = NULL;
}

//добавляем элемент в конец ( тк последний элемент Null, то мы должны послднему элементу передать ссылку на новый элемент, а новому передаём ссылку на Null)
void node_col_add(Node_row *node_row, Node_col *new_node){
	Node_col *tmp = node_row->begin_row;
	if(tmp == NULL){
		node_row->begin_row = new_node;
		new_node->next = NULL;
		return;
	}
	while(tmp->next){
		tmp = tmp->next;
	}
	tmp->next = new_node;
	new_node->next = NULL;
}

//просто добавляем элементы в столбец
void node_col_add_before(Node_row *node_row, Node_col *after_node_col, Node_col *new_node){
	Node_col *tmp = node_row->begin_row;
	if(node_row->begin_row == after_node_col){
		new_node->next = node_row->begin_row;
		node_row->begin_row = new_node;
	}
	while(tmp && (tmp->next != after_node_col)){
		tmp = tmp->next;
	}
	if(tmp){
		new_node->next = tmp->next;
		tmp->next = new_node;
	}
}

//добавление ряда
void node_row_add(Matrix matrix, Node_row *new_row){
	Node_row *tmp = matrix->head_row;
	if(tmp == NULL){
		matrix->head_row = new_row;
		new_row->next = NULL;
		new_row->begin_row = NULL;
		return;
	}
	while(tmp->next){
		tmp = tmp->next;
	}
	tmp->next = new_row;
	new_row->next = NULL;
	new_row->begin_row = NULL;
}

//создаём матрицу (выделяем память)
Matrix matrix_create(int n, int m){
	Matrix matrix = (Matrix) calloc(1, sizeof(*matrix));
	if(matrix == NULL){
		printf("Ошибка. Не хватает памяти\n");
		exit(1);
	}
	matrix->n = n;
	matrix->m = m;
	matrix->entries = 0; //количество элементов
	Node_row *node_row;
	for(int i=0; i<n; ++i){
		node_row = node_row_create();
		node_row_add(matrix, node_row);
		node_row = node_row->next;
	}
	return matrix;
}

//вставка элемента
void elem_set(Matrix mat, int i, int j, double value){
	if(value != 0){
		mat->entries++; //увеличиваем количество элементов
		Node_row *node_row = mat->head_row;
		for(; i>1; --i){
			node_row = node_row->next;
		}
		Node_col *node_col = node_row->begin_row;
		bool insert_last = true;//пусть столбец последний
		while(node_col){//пока есть столбцы
			if(node_col->column < j){ //если не дошли до нужного столбца
				node_col = node_col->next; //переходим к следующему 
			} else { //если мы дошли, то что-то делаем
				Node_col *new_node = node_col_create();
				node_col_add_before(node_row, node_col, new_node);
				new_node->column = j;
				new_node->element = value;
				insert_last = false; //столбец не последний
				break;
			}

		}
		if(insert_last){ //если мы не дошли до нужного столбца, то значит столбец последний;
		//если добавляем в конец, то пользуемся функцией nod_col_add
			node_col = node_col_create();
			node_col_add(node_row, node_col);
			node_col->column = j;
			node_col->element = value;
		}
	}
}
//получение элемента для вывода
double elem_get(Matrix mat, int i, int j){
	if(mat->head_row == NULL){
		printf("Ошибка. Невозможно получить элемент\n");
		exit(1);
	}
	Node_row *row = mat->head_row;
	while(i>1){
		row = row->next;
		--i;
	}
	if(row == NULL){
		printf("Ошибка. Невозможно получить элемент\n");
		exit(1);
	}
	else {
		for(Node_col *h = row->begin_row; h; h=h->next){
			if(h->column == j){
				return h->element;
			}
		}
		return 0;
	}
}
//вывод
void print_matrix(Matrix mat){
	for(int i = 1; i <= mat->n; ++i){
        for(int j = 1; j <= mat->m; ++j){
			double number = elem_get(mat, i, j);
			printf("%.1lf\t", number);
		}
		printf("\n");
	}
	printf("\n");
}

//вывод внутреннего представления
void print_inner(Matrix mat){
	for(int i = 1; i <= mat->n; ++i){
		printf("%d  ||", i);
        for(int j = 1; j <= mat->m; ++j){
			double number = elem_get(mat, i, j);
			if (number != 0)
			{
				printf("  %d  |  %.1lf  ||", j, number);
			}
		}
		printf("0  |  ");
	}
	printf("\n");
}
//функция к варианту
void solution(Matrix mat, int a){
	int res_row; //нужный ряд (строка) (чтобы поделить потом элементы на пересечении на нужное число)
	int res_col; //нужный столбец (чтобы поделить потом элементы на пересечении на нужное число)
	double min_diff = -1.0; //минимальная разность
	double close_value; //ближайшее значение

//ищем ближайший элемент
	for(int i = 1; i <= mat->n; ++i){
        for(int j = 1; j <= mat->m; ++j){
			double number = elem_get(mat, i, j);
			if (-1.0 == min_diff) {
				min_diff = fabs(a - number);
				close_value = number;
				res_row = i;
				res_col = j;
			} else if (fabs(a - number) < min_diff) {
				min_diff = fabs(a - number);
				close_value = number;
				res_row = i;
				res_col = j;
			}
		}
	}

//вывод матрицу, не меняя её
	for(int i = 1; i <= mat->n; ++i){
        for(int j = 1; j <= mat->m; ++j){
			double number = elem_get(mat, i, j);
			if (i == res_row || j == res_col) {
				number = number / close_value;
			}
			printf("%.1lf\t", number);
		}
		printf("\n");
	}
	printf("\n");
}


int main()
{
	int n, m, chose, a, b;
	double x;
	int g = 1;
	Matrix mat;

	while(g == 1){
		printf("Меню:\n\nВыберите действие:\n1)Ввести матрицу\n2)Печать матрицы в нормальном виде\n3)Печать внутреннего представления матрицы\n4)Выполнить задание над матрицей\n5)Выход\n");
		scanf("%d", &chose);
		switch (chose){
			case 1:
				printf("Введите размер матрицы:\n");
			    scanf("%d %d", &n, &m);
			    mat = matrix_create(n,m);
			    printf("Введите матрицу:\n");
			    for(int i = 1; i <= n; ++i){
			        for(int j = 1; j <= m; ++j){
			            scanf("%lf", &x);
			            elem_set(mat, i, j, x);
			        }
			    }
			    break;
			case 2:
				if(mat == NULL){
					printf("Матрица пустая\n");
				} else {
					printf("Обычное представление матрицы:\n");
					print_matrix(mat);
				}
				break;
			case 3:
				if(mat == NULL){
					printf("Матрица пустая\n");
				} else {
					printf("Внутреннее представление матрицы:\n0  |  ");
					print_inner(mat);
				}
				break;
			case 4:

				printf("Введите число a\n");
				scanf("%d", &a);
				solution(mat, a);
				break;
			case 5:
				g = 0;

		}
	}	
}
