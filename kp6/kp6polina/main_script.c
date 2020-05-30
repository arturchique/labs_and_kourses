#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.h"

int read_bin(FILE *in, passenger *person){
	fread(person->lname, sizeof(char), NAME_SIZE, in);
	fread(person->initials, sizeof(char), NAME_SIZE, in);
	fread(&person->count, sizeof(int), 1, in);
	fread(&person->weight, sizeof(int), 1, in);
	fread(person->destination, sizeof(char), NAME_SIZE, in);
	fread(person->departure, sizeof(char), NAME_SIZE, in);
	fread(person->changed, sizeof(char), NAME_SIZE, in);
	fread(person->childes, sizeof(char), NAME_SIZE, in);
    
    return !feof(in);
}

void print_bd(passenger *person){
    printf("%s  ", person->lname);
    printf("%s  ", person->initials);
    printf("%d  ", person->count);
    printf("%d  ", person->weight);
    printf("%s  ", person->destination);
    printf("%s  ", person->departure);
	printf("%s  ", person->changed);
    printf("%s\n", person->childes);
}

void find_min_weight(passenger* person, int max_count, int min_weight){
	if (person->count > max_count)
	{
		max_count = person->count;
		min_weight = person->weight;
	}
	else if ((person->count == max_count) && (person->weight <= min_weight))
	{
		min_weight = person->weight;
	}
}

void find_res(passenger* person, int max_count, int min_weight) {
	if ((person->count == max_count) && (person->weight == min_weight))
		print_bd(person);
}

int main(int argc, char *argv[]){
    int max = 0;
	int a;
    FILE *in = fopen(argv[2], "r");
    passenger stud;
    if(strcmp(argv[1], "-f") == 0){
		do
		{
			a = read_bin(in, &stud);
			print_bd(&stud);
		} while (a);
    }
    else if (strcmp(argv[1], "-p") == 0){
		int max_count = 0;
		int min_weight = 99999;
		do
		{
			a = read_bin(in, &stud);
			find_res(&stud, max_count, min_weight);

		} while (a);
		do
		{
			a = read_bin(in, &stud);
			find_res(&stud, max_count, min_weight);

		} while (a);
    }
    fclose(in);
	return 0;
}