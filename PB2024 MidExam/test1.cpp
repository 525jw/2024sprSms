#include <stdio.h>

/* (x, y)가 1 사분면에 있으면 1을 리턴하고,
 * 2, 3, 4 사분면에 있으면 각각 2, 3, 4를 리턴한다.
 * (x, y)가 좌표축 위에 있으면 0을 리턴한다. 
 */
int quadrant(int x, int y){
    if(x>0 && y>0) return 1;
    else if(x<0 && y>0) return 2;
    else if(x<0 && y<0) return 3;
    else if(x>0 && y<0) return 4;
    else return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", quadrant(x, y));
    }
}