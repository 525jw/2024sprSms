#include <stdio.h>

int sumAry2D_f1(int ary[][3], int ROW, int COL); // 배열 파라미터, 권장
int sumAry2D_f2(int(*ary)[3], int ROW); // 배열 포인터
int sumAry2D_f3(int ary[3][3]);

int main(void)
{
	int i, j;
	int ary2D[][3] = { { 1, 2, 3 }, { 4, 5, 6 }, {7, 8, 9} };

	printf("sumAry2D_f1() %d\n", sumAry2D_f1(ary2D, 3, 3));
	printf("sumAry2D_f2() %d\n", sumAry2D_f2(ary2D, 3));
	printf("sumAry2D_f3() %d\n", sumAry2D_f3(ary2D));
	return 0;
}

int sumAry2D_f1(int **ary, int ROW, int COL)
//int sumAry2D_f1(int ary[][3], int ROW, int COL)
{
	int sum = 0, i = 0, j = 0;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			sum += ary[i][j];
			//sum += *(*(ary+i)+j);
		}
	}

	return sum;
}

int sumAry2D_f2(int(*ary)[3], int ROW)
{
	int sum = 0, i = 0, j = 0;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < 3; j++)
		{
			sum += ary[i][j];
			//sum += *(*(ary+i)+j);
		}
	}

	return sum;
}

int sumAry2D_f3(int ary[3][3])
{
	int sum = 0, i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			sum += ary[i][j];
			//sum += *(*(ary+i)+j);
		}
	}

	return sum;
}
