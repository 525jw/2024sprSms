#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#define TRUE 1
#define FALSE 0

// maze search
int maze[MAX_ROW_SIZE + 2][MAX_COL_SIZE + 2];
int mark[MAX_ROW_SIZE + 2][MAX_COL_SIZE + 2] = { 0 };

typedef struct {
	short int vert;
	short int horiz;
} offsets;
offsets move[8] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int EXIT_ROW;
int EXIT_COL;

void path(void);


int main(void)
{
	int r, c;
	int nRows, nCols;
	FILE *fp;	

	fopen_s(&fp, "input.txt", "r");
	if(fp == NULL )
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	fscanf_s(fp, "%d%d", &nRows, &nCols);
	for ( r = 0; r <= nRows+1; r++ )
	{
		for ( c = 0; c <= nCols+1; c++ )
		{
			if ( r == 0 || r == nRows+1 || c == 0 || c == nCols+1 )
				maze[r][c] = 1;
			else
				fscanf_s( fp, "%d", &maze[r][c] );
		}
	}


	EXIT_ROW = nRows;
	EXIT_COL = nCols;

	path();
	
	return 0;
}

void path(void)
{
	/*output a path through the maze if such a path exists */
	STACK stack;
	element position;
	int  row, col, nextRow, nextCol, dir, found = FALSE;


	stack_init(&stack);
	position.row = position.col = position.dir = 1;
	push(&stack, position);
	
	while( isempty(stack) && !found)
	{
		position = pop(&stack);
		row = position.row;  col = position.col; 
		dir = position.dir;

		while( dir < 8 && !found )
		{ /* move n direction dir */
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;

			if( nextRow == EXIT_ROW && nextCol == EXIT_COL )
				found = TRUE;
			else if( !maze[nextRow][nextCol] && !mark[nextRow][nextCol])	
			{
				mark[nextRow][nextCol] = 1;
				position.row = row;		position.col = col;
				position.dir = ++dir;
				push(&stack, position);
				row = nextRow; col = nextCol; dir = 0;
			}else ++dir;
		}//while
	}//while

	if(found)
	{
		printf("The path is: \n");
		printf("row col\n");
		sprint(stack);
//		for( i = 0; i <= top; i++)
//			printf("%2d%5d\n", stack[i].row, stack[i].col);
		printf("%2d%5d\n", row, col);
		printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
	}
	else 
		printf("The maze does not have a path\n");
}

