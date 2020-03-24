#include <stdio.h>

int main()
{	
	FILE *file;
	file = fopen("tests15.txt", "r");
	int n, m;
	char end[11] = "MoreMatrix";
	int maxOfString, maxString;
	fscanf(file, "%d %d", &n, &m);
	int matrix[n][m];  // Матрица
	int a, max = 0;  	   // Читаемая перемменная, максимум из сумм
	while (end[1] == 'M')	
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				fscanf(file, "%d", &matrix[i][j]);
			}
		}
		maxOfString = matrix[0][0];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (matrix[i][j] > maxOfString)
				{
					maxOfString = matrix[i][j];
					maxString = i;
				}
			}
		}

		for (int i = 0; i < m; ++i)
		{
			max = max + matrix[maxString][i];
		}
		printf("%d \n",max);
		fscanf(file, "%30s", end);
	}
	return 0;
}
