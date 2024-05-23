#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _fruit fruit_t;

struct _fruit {
    char name[20];
    int price;
};

/*
 qsort() function is declared in stdlib.h:
 void qsort(void *base, // pointer to the first element of the array.
            size_t nitems, // number of elements.
            size_t size,   // size of each element in bytes.
            int (*compare)(const void *, const void*)) // function pointer to compare two elements.
*/

int compare(const void* x, const void* y);
fruit_t* read_fruits(FILE* fp, int n);
void write_fruits(FILE* fp, int n, fruit_t* fruits);

int main()
{
    int n; fscanf(stdin, "%d\n", &n);
    fruit_t* fruits = read_fruits(stdin, n);
    qsort(fruits, n, sizeof(fruit_t), compare);
    write_fruits(stdout, n, fruits);
}

int compare(const void* x, const void* y) {
    fruit_t* tmpx = (fruit_t*)x;
    fruit_t* tmpy = (fruit_t*)y;
    if (tmpx->price == tmpy->price) {
        return -strcmp(tmpy->name, tmpx->name);
    }
    else return tmpy->price - tmpx->price;
}
fruit_t* read_fruits(FILE* fp, int n) {
    fruit_t* fruits = (fruit_t*)malloc(sizeof(fruit_t) * n);
    for (int i = 0;i < n;i++)
        fscanf(fp, "%s %d", &fruits[i].name, &fruits[i].price);
    return fruits;
}
void write_fruits(FILE* fp, int n, fruit_t* fruits) {
    for (int i = 0;i < n;i++) {
        fprintf(fp, "%s %d", fruits[i].name, fruits[i].price);
        if (i < n - 1) fprintf(fp, "\n");
    }
}
