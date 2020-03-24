#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int m[n][n];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &m[i][j]);
		}
	}
	int end = 0;
	printf("%d\n", m[n][n]);
	int i = 0, j = n-1, flagy = 0;
	while (end != 1){
		printf("%d\n", m[i][j]);
		if (i!=0 && i!=n-1 && j!=0 && j!=n-1)
		{
			if (flagy = 1) 
			{
				i+=1;
				j+=1;
			} else {
				i-=1;
				j-=1;
			}
		} else if (i == 0 && flagy == 0 && j!=1)
		{
			j-=1;
			flagy = 1;
		} else if (i == 0 && flagy == 1 && j!=1)								
		{
			i+=1;
			j+=1;
		} else if (j == n-1 && flagy == 1 && i!=n) 
		{
			i+=1;
			flagy = 0;
		} else if (j == n-1 && flagy == 0 && i!=n) 
		{
			i-=1;
			j-=1;
		} else if (j == 0 && i == 0)
		{
			flagy = 1;
			i+=1;
			j+=1;
		} else if (i == n-1 && (j == n-1 || flagy == 1) )
		{
			flagy = 0;
			j-=1;
		} else if (i=n-1 && flagy == 0 && i!=n-1)
		{
			j-=1;
			i-=1;
		} else if (j == 0 && flagy == 0 && i!=n-1)
		{
			flagy = 1;
			i+=1;
		} else if (j == 0 && flagy == 1 && i!=n-1)
		{
			j+=1;
			i+=1;
		} else if (j == 0 && i == n-1)
		{
			end = 1;
		}
		
	}

	
	return 0;
}

