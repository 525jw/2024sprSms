#include <stdio.h>

typedef struct _fruit fruit_t;

struct _fruit {
    int price;
    char name[100];
};

fruit_t *find_both(int n, fruit_t *items, fruit_t **maxptr){
    fruit_t frst={-1,""};
    int index=0;
    for(int i=0;i<n;i++){
        if(frst.price<items[i].price){
            frst=items[i];
            index=i;
        }
    }
    frst.price=-1;
    *maxptr=&items[index];
    for(int i=0;i<n;i++){
        if(i==index) continue;
        if(frst.price<items[i].price){
            frst=items[i];
        }
    }
    items[0]=frst;
    return &items[0];
}

int main()
{
    fruit_t fruits[20];
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
        scanf("%s %d", fruits[i].name, &fruits[i].price);

    fruit_t *maxptr, *sndptr;
    sndptr = find_both(n, fruits, &maxptr);
    printf("%s %d\n", maxptr->name, maxptr->price);
    printf("%s %d\n", sndptr->name, sndptr->price);
}