#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "person.h"

void usage() {
    printf("Usage: program filename\n");
}

int readperson(FILE* in, person* stud) {
	fscanf(in, "%s", stud->fam);
	fscanf(in, "%s", stud->init);
	fscanf(in, "%s", stud->sex);
	fscanf(in, "%d", &stud->group);
	fscanf(in, "%d", &stud->inform);
	fscanf(in, "%d", &stud->linal);
	fscanf(in, "%d", &stud->discra);
	fscanf(in, "%d", &stud->matan);

	return !feof(in);
}

int writeperson_bin(FILE* out, person* stud) {
	fwrite(stud->fam, sizeof(char), 20, out);
	fwrite(stud->init, sizeof(char), 9, out);
	fwrite(stud->sex, sizeof(char), 7, out);
	fwrite(&stud->group, sizeof(int), 1, out);
	fwrite(&stud->inform, sizeof(int), 1, out);
	fwrite(&stud->linal, sizeof(int), 1, out);
	fwrite(&stud->discra, sizeof(int), 1, out);
	fwrite(&stud->matan, sizeof(int), 1, out);

}

int main(int argc, char* argv[]) {
	FILE* in = fopen(argv[1], "r");
	FILE* out = fopen(argv[2], "w");

	if (!in || !out) {
		printf("Error, can't open file\n");
	}

	person stud;

	while (readperson(in, &stud)) {
		writeperson_bin(out, &stud);
	};

	fclose(in);
	fclose(out);

}