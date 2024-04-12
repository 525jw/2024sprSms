#include <iostream>
#include <vector>

using namespace std;

int sum(int n, vector<int> S);

int main() {
    int n;
    scanf("%d", &n);
    vector<int> S(n+1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &S[i]);
    printf("%d", sum(n, S));
}

int sum(int n, vector<int> S) {
    int i,sum=0;
    for(i=1;i<=n;i++){
        sum+=S[i];
    }
    return sum;
}
