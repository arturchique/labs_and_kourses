#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#include "person.h"
#include "group_diff.h"


int read_bin(FILE *in, person *stud){
	// Чтение одного студента
	// Вызывается в цикле While чтобы за одну итерацию рассматривать одного студента
    fread(stud->fam, sizeof(char), 20, in);
    fread(stud->init, sizeof(char), 9, in);
    fread(stud->sex, sizeof(char), 7, in);
    fread(&stud->group, sizeof(int), 1, in);
    fread(&stud->inform, sizeof(int), 1, in);
    fread(&stud->linal, sizeof(int), 1, in);
    fread(&stud->discra, sizeof(int), 1, in);
    fread(&stud->matan, sizeof(int), 1, in);
    
    // Возвращает true если файл не закончился
    return !feof(in);
}

void print_bd(person *stud){
	// Печатает данные об одном студенте в строку 
    printf("%s  ", stud->fam);
    printf("%s  ", stud->init);
    printf("%s  ", stud->sex);
    printf("%d  ", stud->group);
    printf("%d  ", stud->inform);
    printf("%d  ", stud->linal);
    printf("%d  ", stud->discra);
    printf("%d\n", stud->matan);
}

void find_result_group(person *stud, FILE *in) {
	// создаем массив минимумов и максимумов для каждой группы (всего их 12)
	// заполняем нулями, чтоб не выхватывать ошибок при сравнении с NULL
	group_diff group_diffs[12];
	for (int i = 0; i < 12; ++i)
	{
		group_diffs[i].min = NULL;
		group_diffs[i].max = NULL;		
	}


	while(read_bin(in, stud)) {
		// заполняем минимум и максимум в существующих группах
		int stud_summary = stud->linal + stud->discra + stud->inform + stud->matan;
		int stud_group_index = stud->group % 100;
		group_diff *current_group = &(group_diffs[stud_group_index]);

		if (current_group->min == NULL && current_group->max == NULL)
		{

			current_group->min = stud_summary;
			current_group->max = stud_summary;

		} else {
			if (stud_summary > current_group->max)
			{
				current_group->max = stud_summary;
			}
			if (stud_summary < current_group->min) 
			{
				current_group->min = stud_summary;
			}
		}
	}

	// Обходим группы и находим самую большую разницу
	int max_diff = 0;
	int group_name;
	for (int i = 0; i < 12; ++i)
	{
		if (group_diffs[i].max == NULL)
		{
			continue;
		}
		if (group_diffs[i].max - group_diffs[i].min > max_diff)
		{
			max_diff = group_diffs[i].max - group_diffs[i].min;
			group_name = 100 + i;
		}	
	}

	printf("%d\n", group_name);
}



void main(int argc, char* argv[])
{
	FILE *in = fopen(argv[2], "r");
    person stud;

	if(strcmp(argv[1], "-f") == 0)
	{
        while(read_bin(in, &stud))
        {
            print_bd(&stud);
        }
    } else if (strcmp(argv[1], "-p") == 0)
    {
    	find_result_group(&stud, in);
    }
}