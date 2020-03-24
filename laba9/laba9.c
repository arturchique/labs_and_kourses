#include <stdio.h>

int main(void)
{	
	int sign(int value) {
		if (value<0)
		{
			return -1;
		} else if (value > 0)
		{
			return 1;
		} else if (value == 0)
		{
			return 0;
		}
	}

	int abs(int value) {
		if (value < 0)
		{
			return -value;
		} else {
			return value;
		}
	}

	int mod (int value, int moder){
	   if(moder < 0)
	   		return mod(value, -moder);   
	   int ret = value % moder;
	   if(ret < 0)
	    	ret+=moder;
	   return ret;
	}

	int max(int v1, int v2) {
		if (v1 > v2){
			return v1;
		} else {
			return v2;
		}
	}

	int fi(int a, int b, int c, int d){
		return ( a/3 - abs(a-d)*sign(a-b) );
	}

	int fj(int a, int b, int c, int d){
		return ( mod(b,10)-mod(max(a,c),(d+1)) );
	}

	int fl(int a, int b, int c, int d){
		return( a + mod((b*d), 5) + c/3 + 3 );
	}






	int i, j, l;
	l=4;
	i=-22;
	j=29;






	int d1, d2;
	int m = 0;
	for (int k = 0; k < 50; ++k)
	{	
		int tmpi, tmpj, tmpl;
		d1 = (i+10)*(i+10)+(j+10)*(j+10);
		d2 = (i+20)*(i+20)+(j+20)*(j+20);
		if ((d1<=100) && (d2<=400)){
			printf ("Точка попала в пересечение окружностей в значениях ");
			printf("%i", i);
			printf(" ");
			printf("%i", j);
			printf(" ");
			printf("на ");
			printf("%i", m);
			printf(" итерации");

			break;
		} else{
			tmpi = fi(i, j, l, k);
			tmpj = fj(i, j, l, k);
			tmpl = fl(i, j, l, k);
			i = tmpi;
			j = tmpj;
			l = tmpl;
			m+=1;
		}
		
	}
	if (m == 50){
		puts ("Точка не попала в пересечение окружностей");
	}


	return 0;
}


