#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int k,cnt=0,callcnt=0;
void hanoi(int n, char src, char via, char dst) {
    callcnt++;
    if (n==1){
        cnt++;
        if(cnt==k) printf("%c -> %c\n", src, dst);
    }
    else {
        hanoi(n-1, src, dst, via);
        hanoi(1, src, via, dst);
        hanoi(n-1, via, src, dst);
    }
}

int main() {
    int n;
    cin >> n >> k;
    hanoi(n, 'A', 'B', 'C');
    cout << callcnt;
}