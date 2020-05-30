#ifndef _grad_h_

#define _grad_h_

#define NAME_SIZE 50

typedef struct{
    char lname[NAME_SIZE];
    char initials[NAME_SIZE];
	int count;
	int weight;
	char destination[NAME_SIZE];
	char departure[NAME_SIZE];
	char changed[NAME_SIZE];
	char childes[NAME_SIZE];
} passenger;

#endif