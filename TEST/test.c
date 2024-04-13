#include <stdio.h>
#define MAX_STACK_SIZE 100

typedef struct {
	int row;
	int col;
	int dir;
} element;

typedef struct {
    int vert;
    int horiz;
} offsets;

offsets move[4];

element stack[MAX_STACK_SIZE];
int maze[100][100];
int mark[100][100];
int top = -1;
int EXIT_COL, EXIT_ROW;

void push(element item) {
    if(top >= MAX_STACK_SIZE-1) return;
    stack[++top] = item;
}

element pop() {
    if(top > -1) return stack[top--];
}

void path(int sx, int sy) {
    move[0].horiz = 0; move[0].vert = -1;
    move[1].horiz = 1; move[1].vert = 0;
    move[2].horiz = 0; move[2].vert = 1;
    move[3].horiz = -1; move[3].vert = 0;

    for(int a=0; a<100; a++) 
        for(int b=0; b<100; b++)
            mark[a][b] = 0;
    
    int i, row, col, next_row, next_col, dir, found = 0;
    element position;
    mark[sx][sy] = 1;
    top = 0;
    stack[0].row = sx; stack[0].col = sy; stack[0].dir = 0;

    while(top > -1 && !found) {
        position = pop();
        row = position.row;
        col = position.col;
        dir = position.dir;
        
        while(dir < 4 && !found) {
            next_row = row + move[dir].vert;
            next_col = col + move[dir].horiz;
            
            if(next_row == EXIT_ROW && next_col == EXIT_COL) found = 1;
            else if(!maze[next_row][next_col] && !mark[next_row][next_col]) {       
                mark[next_row][next_col] = 1;
                position.row = row;
                position.col = col;
                position.dir = ++dir;
                push(position);
                row = next_row;
                col = next_col;
                dir = 0;
            } 
            else ++dir;
        }
    }
    if(found) {
        printf("The path is:\n");
        // for (i=0; i<=top; i++)
        //     printf("%2d%5d\n", stack[i].row, stack[i].col);
        // position.row = row;
        // position.col = col;
        // position.dir = 0;
        // push(position);
    } else {
        printf("No path!\n");
    }
}

int main() {
	FILE* fp1;
	int x, y, sx, sy, fx, fy;

	for (int i = 0; i < 4; i++) {
        int tmp[100][100] = {0, };
		if(i == 0) fp1 = fopen("maze1.txt", "r");
		else if(i == 1) fp1 = fopen("maze2.txt", "r");
		else if(i == 2) fp1 = fopen("maze3.txt", "r");
		else fp1 = fopen("maze4.txt", "r");

		fscanf(fp1, "%d %d", &x, &y);
		for (int j = 0; j <= x+1; j++) {
			for (int k = 0; k <= y+1; k++) {
				if (j == 0 || k == 0 || j == x+1 || k == y+1) maze[j][k] = 1;
				else fscanf(fp1, "%d", &maze[j][k]);
			}
		}

        fscanf(fp1, "%d %d %d %d", &sx, &sy, &fx, &fy);

        EXIT_ROW = fx+1;
        EXIT_COL = fy+1;

        printf("MAZE\n");
		for (int j = 1; j <= x; j++) {
			for (int k = 1; k <= y; k++)
				printf("%2d", maze[j][k]);
			printf("\n");
		}

        path(sx+1, sy+1);

        //for (i=0; i<=top; i++)
        //    tmp[stack[i].row][stack[i].col] = 1;

		for (int j = 1; j <= x; j++) {
			for (int k = 1; k <= y; k++) { 
                if(sx + 1 == j && sy + 1 == k) printf(" S");
				else if(fx + 1 == j && fy + 1 == k) printf(" F");
                //else if(tmp[j][k] == 1) printf(" X");
                else printf("%2d", maze[j][k]);
            }
			printf("\n");
		}
		fclose(fp1);
	}
}