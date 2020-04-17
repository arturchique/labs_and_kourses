#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "person.h"

void usage()
{
	printf("Usage:program filename\n");
}

int main(int argc, char* argv[])
{
if (argc !=2){
	usage();
	return 1;
}
int print_bd( person *p ){
printf("+----------------+----------+---------+--------+-------------+--------------+---------------+---------------+\n");

printf("|         Фамилия|  Инициалы|      Пол|  Группа|  Информатика|  Лин. алгебра|  Дискр. матем.|  Мат. анализ  |\n");

printf("+----------------+----------+---------+--------+-------------+--------------+---------------+---------------+\n");

while (fread(&p, sizeof(p), 1, file) == 1)

{

printf("|%16s|%10s|%10s|%10d|%5d|%5d|%5d|%5d|\n",

p.fam,
p.ini,
p.sex,
&p.group,
&p.inform,
&p.linal,
&p.discra,
&p.matan

);

printf("+----------------+----------+---------+--------+-------------+--------------+---------------+\n");
}

person p;
FILE *in = fopen(argv[1],"rb");
if (!in){
	perror("Can't open file!");
	return 2;
}
float minsrb = 5.0;
while (fread(&p, sizeoff(p), 1, in) ==1 ){
	float srb = (p.inform + p.linal + p.discra + p.matan)/float 4;
	if srb < minsrb
		minsrb = srb;
}
fseek (in, 0, SEEK_SET);
int n2 = 0, n3 = 0, n4 = 0, n5 = 0; 
while (fread(&p, sizeoff(p), 1, in) == 1){
	if (p.group == 102) {
		if((p.sex == men)&&(((p.inform + p.linal + p.discra + p.matan)/float 4)==minsrb))
			n2++;
		else break;
	}
	if (p.group == 103) {
		if((p.sex == men)&&(((p.inform + p.linal + p.discra + p.matan)/float 4)==minsrb))
			n3++;
		else break;
	}
	if (p.group == 104) {
		if((p.sex == men)&&(((p.inform + p.linal + p.discra + p.matan)/float 4)==minsrb))
			n4++;
		else break;
	}
	if (p.group == 105) {
		if((p.sex == men)&&(((p.inform + p.linal + p.discra + p.matan)/float 4)==minsrb))
			n5++;
		else break;
	}
	
	}
	

}
