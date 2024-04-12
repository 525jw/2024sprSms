#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void binsearch(int n, vector<int> S, int x, int& location);

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> S(n+1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &S[i]);
    sort(S.begin() + 1, S.end());
    while (m--) {
        int x, location;
        scanf("%d", &x);
        binsearch(n, S, x, location);
        if (location > 0)
            printf("%d is in %d.\n", x, location);
        else
            printf("%d is not in S.\n", x);
    }
}

void binsearch(int n, vector<int> S, int x, int& location){
    int stp=1;
    int edp=n;
    while(stp<=edp){
        int mid=(stp+edp)/2;
        if(S[mid]==x){
            location=mid;
            return;
        }
        else if(S[mid]>x) edp=mid-1;
        else stp=mid+1;
    }
    location=0;
}