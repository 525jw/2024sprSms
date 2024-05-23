#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _fruit fruit_t;

struct _fruit {
    char name[20];
    int offset;
};

void traverse_fruits(FILE *fp);

int main()
{
    traverse_fruits(stdin);
}

void traverse_fruits(FILE *fp){
    int head;
    fread(&head,sizeof(int),1,fp);
    fseek(fp,head*sizeof(fruit_t),SEEK_CUR);

    fruit_t fruit;
    while(1){
        fread(&fruit,sizeof(fruit_t),1,fp);
        printf("%s\n",fruit.name);
        if(fruit.offset==-1)
            break;
        fseek(fp,fruit.offset*sizeof(fruit_t),SEEK_CUR);
    }
}