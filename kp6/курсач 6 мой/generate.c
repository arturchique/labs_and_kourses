#include <stdio.h>

#include "structure.h"

int readperson(FILE *in, person *stud){
    fscanf(in, "%s", stud->lname);
    fscanf(in, "%s", stud->initials);
    fscanf(in, "%s", stud->gender);
    fscanf(in, "%d", &stud->school_num);
    fscanf(in, "%s", stud->has_medal);
    fscanf(in, "%d", &stud->rating);
    fscanf(in, "%s", stud->essay);

    return !feof(in);
}

int writeperson_bin(FILE *out, person *stud){
    fwrite(stud->lname, sizeof(char), NAME_SIZE, out);
    fwrite(stud->initials, sizeof(char), NAME_SIZE, out);
    fwrite(stud->gender, sizeof(char), NAME_SIZE, out);
    fwrite(&stud->school_num, sizeof(int), 1, out);
    fwrite(stud->has_medal, sizeof(char), NAME_SIZE, out);
    fwrite(&stud->rating, sizeof(int), 1, out);
    fwrite(stud->essay, sizeof(char), NAME_SIZE, out);

}

int main(int argc, char *argv[]){
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");
    if(!in || !out){
        printf("Error, can't open file\n");
    }
    person stud;
    while(readperson(in, &stud)){
        writeperson_bin(out, &stud);
    };

    fclose(in);
    fclose(out);
}