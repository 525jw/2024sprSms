#include <stdio.h>

int main()
{
    int i, n, s=0;
    scanf("%d", &n);
    i = 0;
    while (i <= n) {
		s = s + i;
        ++i;
    }
    printf("%d", s);
}