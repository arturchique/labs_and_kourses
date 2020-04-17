#ifndef _person_h
#define _person_h

typedef struct {
	char fam[20]; // Фамилия
	char init[9]; // Инициалы
	char sex[7]; //Пол
	int group; //Номер группы
	int inform; //Оценка по информатике
	int linal; //Оценка по линалу
	int discra; // Оценка по дискретной математике
	int matan; // Оценка по математическому анализу
} person;

#endif