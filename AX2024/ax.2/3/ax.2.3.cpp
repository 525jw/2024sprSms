#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

typedef long long long_t;

long_t fun(long_t n) {
    return pow(4,1+log2(n));
}

int main() {
    long_t n;
    scanf("%lld", &n);
    printf("%lld", fun(n));
}