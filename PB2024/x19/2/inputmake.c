#include <stdio.h>

typedef struct _fruit fruit_t;

struct _fruit {
    char name[20];
    int price;
};

int main()
{
    fruit_t fruits[10] = {
        {"banana", 1000},
        {"kiwi", 1000},
        {"apple", 500},
        {"tomato", 500},
        {"lemon", 1500},
        {"melon", 500},
        {"pear", 500},
        {"blueberry", 1000},
        {"strawberry", 1500},
        {"orange", 1000}
    };
    int n = 10;

    FILE *fout = fopen("input.bin", "wb");
    fwrite(&n, sizeof(int), 1, fout);
    fwrite(fruits, sizeof(fruit_t), 10, fout);
    fclose(fout);
}