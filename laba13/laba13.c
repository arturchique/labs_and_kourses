
#include <stdio.h>	
#include <ctype.h>

int main()
{
	int flag = 0;
	unsigned int word1, word2, tmp;
	char c;
	c = tolower(getchar());
	if (c >= 'a' || c <= 'z')
	{
		word1 = 1u << (c-'a');
		word2 = (1u << (c-'a')) & 0;
	}
	while (c != ' ') {
		word1 = word1 | (1u <<(c-'a'));
		c = tolower(getchar());
	}

	while (c != '\n')
	{
		c = tolower(getchar());
		if (c == ' ')
		{
			continue;
		}
		while (c!= ' ') {
			word2 = word2 | (1u <<(c-'a'));
			c = tolower(getchar());
		}
		if ((word2 & word1) != 0 )
		{
			flag = 0;
			tmp = word1;
			word1 = word2;
			word2 = tmp;
		} else
		{
			printf("Есть\n");
			break;
		}


	}
	if (flag == 0)
	{
		printf("Нет\n");
	}

	return 0;
}
