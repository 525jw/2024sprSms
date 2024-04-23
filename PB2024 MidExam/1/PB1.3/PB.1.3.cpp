#include <stdio.h>

int main()
{
    int n, m, f=1;
    scanf("%d %d", &n, &m);
    while (n <= m) {
        f = f * n;
        ++n;
    }
    printf("%d", f);
}