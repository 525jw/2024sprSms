//... C Language program to implement the Multiple Stacks
#include < stdio.h >
#include <string.h>
#include <stdlib.h>
#define max_s 10
#define name_s 10
#define  MAX_LEN  100

typedef struct {
	char name[name_s];
} s_data;
s_data stack[max_s];
char data[name_s];
int top[max_s], bott[max_s], limit[max_s];

int push(s_data stack[max_s], int sno, int top[], int limit[], char *data);
int pop(s_data stack[max_s], int sno, int top[], int bott[], char *data);
void sprint(int no, int top[], int bott[]);

void main()
{
	int n, size, sno;

	int i, option, reply;

	FILE* fp;
	char line[MAX_LEN];
	char *delimiter = " \n";	// delimiter for tokenizing
	char *context;
	char *op = NULL;

	printf("How Many Stacks ? : ");
	scanf_s("%d", &n);
	getchar();
	size = max_s / n; //... Get Max. size for each Stack
					//... Initialize bottom for each Stack
	bott[0] = -1; //... Bottom of first Stack is -1
	for (i = 1; i < n; i++)
		bott[i] = bott[i - 1] + size;
	//... Initialize Limit of each Stack
	for (i = 0; i < n - 1; i++) //... Limit of i'th Stack is bottom of i'th Stack + Size
		limit[i] = bott[i] + size;
	limit[i] = max_s - 1;
	//... Initialize top of each Stack
	//... Initial value for i'th Stack is equal to its Bottom Value
	for (i = 0; i < n; i++)
		top[i] = bott[i];
	//... Process the Stacks
	printf("\n");

	if (fopen_s(&fp, "input.txt", "r"))
		exit(1);
	while (1)
	{ 
		if(!fgets(line, sizeof(line), fp))
			exit(EXIT_FAILURE);

		op = strtok_s(line, delimiter, &context);

		if (!strcmp(op, "add")) // addq
			option = 1;
		else if (!strcmp(op, "delete")) // deleteq
			option = 2;
		else if (!strcmp(op, "sprint"))
			option = 3;
		else if (!strcmp(op, "quit"))
			option = 4;
		else 
			option = 5;
		sno = -1;
		switch (option)
		{
		case 1: //... Push
			sscanf_s(line + strlen(op) + 1, "%d%s", &sno, data, sizeof(data));
			if ((sno < 0) || (sno > n-1)) {
				printf("stack number error, try again \n");
				break;
			}
			reply = push(stack, sno, top, limit, data);
			if (reply == -1)
				printf("Stack %d is Full\n", sno);
			else
				printf("%s is Pushed in Stack No. %d \n", data, sno);
			break;
		case 2: //... Pop
			sscanf_s(line + strlen(op) + 1, "%d", &sno);
			if ((sno < 0) || (sno > n - 1)) {
				printf("stack number error, try again \n");
				break;
			}
			reply = pop(stack, sno, top, bott, data);
			if (reply == -1)
				printf("Stack %d is Empty \n", sno);
			else
				printf("%s is popped from Stack No. %d \n", data, sno);
			break;
		case 3:
			sscanf_s(line + strlen(op) + 1, "%d", &sno);
			if ((sno < 0) || (sno > n - 1)) {
				printf("stack number error, try again \n");
				break;
			}
			printf("\n");
			sprint(sno, top, bott);
			break;
		case 4: 
			printf("\nProgram end\n");
			for (i = 0; i < n; i++)
			{
				printf("\nstack %d :\n",i);
				sprint(i, top, bott);
			}
			break;
		defaut :
			printf("\nwrong command, try again!! \n\n");
			break;
		} // switch
	} //while end
	fclose(fp);
} // main

int push( s_data fstack[], int sno, int top[], int limit[], char *n_data)
{
	if (top[sno] == limit[sno])
		return(-1);
	else
	{
		top[sno]++;
		strcpy_s(fstack[top[sno]].name, strlen(n_data)+1, n_data);
		return(1);
	} // else
} // push

int pop(s_data stack[], int sno, int top[], int bott[], char *data)
{
	if (top[sno] == bott[sno])
		return(-1);
	else
	{

		strcpy_s(data, sizeof(stack[top[sno]].name), stack[top[sno]].name);
		top[sno]--; //... Or top[sno] = top[sno] -1
		return(1);
	} // else
} // pop

void sprint(int no, int top[], int bott[])
{
	int ti;
	if (top[no] > bott[no]){
		for (ti = top[no]; ti > bott[no]; ti--) 
			printf("%s \n", stack[ti].name);
		printf("\n");
		}
	else
		printf("stack %d is empty\n", no);
}
