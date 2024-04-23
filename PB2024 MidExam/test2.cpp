#include <stdio.h>

/* 13자리 ISBN 번호의 12자리 번호에 대하여
 * check digit을 리턴한다.
 */
int check_digit(int isbn[]){
    int m = (10 - (isbn[0]+3*isbn[1]+isbn[2]+3*isbn[3]+isbn[4]+3*isbn[5]+isbn[6]+3*isbn[7]+isbn[8]+3*isbn[9]+isbn[10]+3*isbn[11])) % 10;
    if(m<0) return m+10;
    else return m;
}

int main()
{
    int isbn[12];
    for (int i = 0; i < 12; i++) {
        isbn[i] = getchar() - '0';
    }
    printf("%d", check_digit(isbn));
}