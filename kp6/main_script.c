#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.h"

int read_bin(FILE *in, person *stud){
    fread(stud->lname, sizeof(char), NAME_SIZE, in);
    fread(stud->initials, sizeof(char), NAME_SIZE, in);
    fread(stud->gender, sizeof(char), NAME_SIZE, in);
    fread(&stud->school_num, sizeof(int), 1, in);
    fread(stud->has_medal, sizeof(char), NAME_SIZE, in);
    fread(&stud->rating, sizeof(int), 1, in);
    fread(stud->essay, sizeof(char), NAME_SIZE, in);
    
    return !feof(in);
}

int print_bd(person *stud){
    printf("%s  ", stud->lname);
    printf("%s  ", stud->initials);
    printf("%s  ", stud->gender);
    printf("%d  ", stud->school_num);
    printf("%s  ", stud->has_medal);
    printf("%d  ", stud->rating);
    printf("%s\n", stud->essay);
}

int find_res(person* stud, char *p1, char *p2){
    int point = stud->rating;
    int res1, res2;
    res1 = atoi(p1);
    res2 = atoi(p2);
    if (point >= res1 && point <= res2){
        printf("%s  ", stud->lname);
        printf("%d\n", point);
    }
}

int main(int argc, char *argv[]){
    int max = 0;
    FILE *in = fopen(argv[2], "r");
    person stud;
    if(strcmp(argv[1], "-f") == 0){
        while(read_bin(in, &stud)){
            print_bd(&stud);
        }
    }
    else if (strcmp(argv[1], "-p") == 0){
        while(read_bin(in, &stud)){
            find_res(&stud, argv[3], argv[4]);
        }
    }
    fclose(in);
}