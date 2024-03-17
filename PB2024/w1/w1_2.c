#include <stdio.h>

int main()
{
    int i, n, s;
    scanf("%d", &n);
    i = 0;
    while (i <= n) {
        s = s + i;
        i++;
    }
    printf("%d", s);
}