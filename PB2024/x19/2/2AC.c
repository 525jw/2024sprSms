#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _fruit fruit_t;

struct _fruit {
    char name[20];
    int price;
};

int compare(const void *x, const void *y);
void read_fruits(FILE *fp, int *n, fruit_t **fruits);
void write_fruits(FILE *fp, int n, fruit_t *fruits);

int main()
{
    int n; fruit_t *fruits;
    read_fruits(stdin, &n, &fruits);
    qsort(fruits, n, sizeof(fruit_t), compare);
    write_fruits(stdout, n, fruits);
}

int compare(const void *x, const void *y){
    fruit_t* tmpx = (fruit_t*)x;
    fruit_t* tmpy = (fruit_t*)y;
    if (tmpx->price == tmpy->price) {
        return -strcmp(tmpy->name, tmpx->name);
    }
    else return tmpy->price - tmpx->price;
}
void read_fruits(FILE *fp, int *n, fruit_t **fruits){

    int t;
    fread(&t,sizeof(int),1,fp);
    *n=t;

    *fruits = (fruit_t*)malloc(sizeof(fruit_t) * (*n));
    fruit_t fruit;
    for (int i = 0;i < *n;i++){
        fread(&fruit ,sizeof(fruit_t),1,fp);
        (*fruits)[i] = fruit;
    }
}
void write_fruits(FILE *fp, int n, fruit_t *fruits){
    for (int i = 0;i < n;i++) {
        fprintf(fp, "%s %d", fruits[i].name, fruits[i].price);
        if (i < n - 1) fprintf(fp, "\n");
    }
}