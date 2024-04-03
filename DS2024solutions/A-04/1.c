#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_TERMS 101
#define MAX_COL 20
#define MAX_ROW 20


typedef struct
{
	int row;
	int col;
	int value;
}term;

void printMatrix(term matrix[]);

int main(void)
{
	term a[MAX_TERMS+1];

	int i, j, row_ind, col_ind, numTerms, sp_ind;
	int sparce[MAX_ROW][MAX_COL] = { 0 };

	printf("원소의 개수를 쓰시오 .. ");
	scanf_s("%d", &numTerms);
	sp_ind = 0;

	a[0].row = MAX_ROW;
	a[0].col = MAX_COL;
	srand((unsigned)time(NULL));

	for (i = 0; i<numTerms; i++)
	{
		row_ind = rand() % MAX_ROW;
		col_ind = rand() % MAX_COL;
		if (sparce[row_ind][col_ind] != 0)
			i--;
		else
			sparce[row_ind][col_ind] = rand() % 100;
	}

	printf("Random generated Matrix(%d,%d) \n",  MAX_ROW, MAX_COL);
	for (i = 0; i<MAX_ROW; i++)
	{
		for (j = 0; j<MAX_COL; j++)
			printf("%5d", sparce[i][j]);
		printf("\n");
	}


	for (i = 0; i<MAX_ROW; i++)
	{
		for (j = 0; j<MAX_COL; j++)
			if (sparce[i][j] != 0) {
				a[++sp_ind].row = i;
				a[sp_ind].col = j;
				a[sp_ind].value = sparce[i][j];
			}
	}
	a[0].value = sp_ind;
	printf("sparce matrix \n");
	for (i = 0; i <= sp_ind; i++)
		printf("%5d, %5d %5d\n", a[i].row, a[i].col, a[i].value);
	return 0;
}

void printMatrix(term matrix[])
{
	int row, col, i, j, element, p;
	row = matrix[0].row;
	col = matrix[0].col;

	element = 0;
	p = 1;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (i == matrix[p].row && j == matrix[p].col)
				element = matrix[p++].value;
			else
				element = 0;
			printf("%4d", element);
		}
		printf("\n");
	}
	getchar();
}