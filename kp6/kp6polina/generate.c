#include <stdio.h>

#include "structure.h"

int readpassenger(FILE *in, passenger *person){
    fscanf(in, "%s", person->lname);
    fscanf(in, "%s", person->initials);
    fscanf(in, "%d", &person->count);
    fscanf(in, "%d", &person->weight);
    fscanf(in, "%s", person->destination);
    fscanf(in, "%s", person->departure);
    fscanf(in, "%s", person->changed);
	fscanf(in, "%s", person->childes);

    return !feof(in);
}

void writepassenger_bin(FILE *out, passenger *person){
    fwrite(person->lname, sizeof(char), NAME_SIZE, out);
    fwrite(person->initials, sizeof(char), NAME_SIZE, out);
    fwrite(&person->count, sizeof(int), 1, out);
    fwrite(&person->weight, sizeof(int), 1, out);
    fwrite(person->destination, sizeof(char), NAME_SIZE, out);
    fwrite(person->departure, sizeof(char), NAME_SIZE, out);
    fwrite(person->changed, sizeof(char), NAME_SIZE, out);
	fwrite(person->childes, sizeof(char), NAME_SIZE, out);

}

int main(int argc, char *argv[]){
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");
    if(!in || !out){
        printf("Error, can't open file\n");
    }
    passenger person;
    while(readpassenger(in, &person)){
        writepassenger_bin(out, &person);
    };

    fclose(in);
    fclose(out);
}