#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct _fruit fruit_t;
struct _fruit {
    char name[20];
    int price;
};

fruit_t fruits[MAX_SIZE];

int compare(const void *, const void *);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s %d", fruits[i].name, &fruits[i].price);
    qsort(fruits, n, sizeof(fruit_t), compare);
    for (int i = 0; i < n; i++)
        printf("%s %d\n", fruits[i].name, fruits[i].price);
}

int compare(const void *a, const void *b){
    fruit_t aa=*(fruit_t*)a;
    fruit_t bb=*(fruit_t*)b;

    if(strlen(aa.name)>strlen(bb.name))
        return 1;
    else if(strlen(aa.name)<strlen(bb.name))
        return -1;
    else{
        if(strcmp(aa.name,bb.name)==0){
            if(aa.price<bb.price)
                return 1;
            else if(aa.price>bb.price)
                return -1;
            else return 0;
        }
        else return strcmp(aa.name,bb.name);
    }
}