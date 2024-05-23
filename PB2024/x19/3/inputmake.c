#include <stdio.h>

typedef struct _fruit fruit_t;

struct _fruit {
    char name[20];
    int offset;
};

int main()
{
    fruit_t fruits[10] = {
        {"banana", 6},
        {"kiwi", 3},
        {"apple", -3},
        {"tomato", -1},
        {"lemon", 0},
        {"melon", 3},
        {"pear", 1},
        {"blueberry", -7},
        {"strawberry", -6},
        {"orange", -4}
    };
    int head = 2;

    FILE *fout = fopen("input.bin", "wb");
    fwrite(&head, sizeof(int), 1, fout);
    fwrite(fruits, sizeof(fruit_t), 10, fout);
    fclose(fout);
}