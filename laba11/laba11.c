
#include <stdio.h>

int isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z'));
}

int isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int main (void)
{
	typedef enum {Separator, Word} State;
	typedef enum {Space, Other} Type;
	State s = Separator;
	Type t = Other;
	int c;
	int res = 0;
	signed long int word1=-1;
	int word2=-1;
	int flagBegin = 0; //флаг на первый символ
	int flagEnd = 0; //флаг на нелегальный символ
	while((c = getchar()) != EOF)
	{
		t = Other;
		if(c == ' ' || c == '\t' || c == '\n' )
		{
			t = Space;
		}
		switch(s)
		{
			case Separator:
			if(t == Other)
			{
				s = Word;
			}
			else
			{
				break;
			}
			case Word:
			if(t == Space)
			{
				s = Separator;
				if(flagBegin == 1)
				{
					flagBegin = 0;
					if(word1 == -1)
						word1 = res;
					else
					{
						if(word2==-1)
							word2=res;
						else
						{
							word1 = word2;
							word2 = res;
						}
					}
				}
				flagEnd = 0;
				res=0;
			}
			else
			{
				if(flagEnd == 0)
				{
					if(flagBegin == 0)
					{
						if(isalpha(c) || isdigit(c))
						{
							flagBegin = 1;
							if ((c >= '0') && (c <= '9')){
								res = res * 16 + (c - 48);
							}
							if((c>= 'A') && (c<='F'))
							{
								res =res*16 + (c-65+10);
							}
							break;
						}
						else
						{
							flagEnd = 1;
							break;
						}
					}
					else
					{
						if(flagBegin == 1)
						{
							if(isalpha(c) || isdigit(c) )
							{
								if ((c >= '0') && (c <= '9')){
									res = res * 16 + (c - 48);
								}
								if((c>= 'A') && (c<='F'))
								{	
									res =res*16 + (c-65+10);
								}
								break;
							}
							else
							{
								flagEnd = 1;
							}
						}
					}
				}
			}
		}
	}



	int mass[70];
	mass[1] = word1 / 16;
	mass[2] = word1 % 16;

	for (int i = 2; i < 64; i = i+2)
	{
		mass[i+1] = mass[i-1] / 16;
		mass[i+2] = mass[i-1] % 16;
	}
	printf("Предпоследнее число в шестнадцатиричной системе:");
	int zero = 0;
	for(int i=64;i>=2;i-=2)
		{
		if (mass[i] == 0 && zero == 0)
		{
			continue;
		} else {
			zero = 1;
			switch(mass[i])
				{
				case 0:printf("0");continue;
				case 1:printf("1");continue;
				case 2:printf("2");continue;
				case 3:printf("3");continue;
				case 4:printf("4");continue;
				case 5:printf("5");continue;
				case 6:printf("6");continue;
				case 7:printf("7");continue;
				case 8:printf("8");continue;
				case 9:printf("9");continue;
				case 10:printf("A");continue;
				case 11:printf("B");continue;
				case 12:printf("C");continue;
				case 13:printf("D");continue;
				case 14:printf("E");continue;
				case 15:printf("F");continue;
				}
		}
		}
	return 0;
} 
