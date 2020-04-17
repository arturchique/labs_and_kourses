#ifndef _grad_h_

#define _grad_h_

#define NAME_SIZE 50

typedef struct{
    char lname[NAME_SIZE];
    char initials[NAME_SIZE];
    char gender[NAME_SIZE];
    int school_num;
    char has_medal[NAME_SIZE];
    int rating;
    char essay[NAME_SIZE];
}person;

#endif