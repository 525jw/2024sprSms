#include <stdio.h>

int main()
{
    int m, n, s;
    scanf("%d %d", &n, &m);
    s = 0;
    while (n <= m) {
        s += n++;
    }
    printf("%d", s);
}