#include "stdio.h"

int SumFrom3(int a) {
	a = a % 1000;
	int sum = 0;
	for (int i = 0; i < 3; ++i)
	{
		sum+= a % 10;
	}
	return sum;
}

int main(void)
{
	int lengh, a, MaxSum, tmpa, result;
	lengh = 0;
	scanf("%d", &a);	//читаем число
	int isOtr = 0;
	if (a<0)
	{
		a = -a;
	}

	tmpa = a;
	while (tmpa>0) 	//длина числа
	{		
		tmpa = tmpa / 10;
		lengh+=1;
	}

	MaxSum = SumFrom3(a);							
	for (int i = 2; i < lengh; ++i)			//сравниваем тройки чисел, ищем максимальную
	{	
		if (SumFrom3(a) > MaxSum)
		{
			MaxSum = SumFrom3(a);
			result = a % 1000;
		}
		a = a / 10;
	}

	printf("%d", result);

}

