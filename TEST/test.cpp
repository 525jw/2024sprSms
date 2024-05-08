#include <iostream>
#include <vector>

using namespace std;

int cache[101][100001];

void solve(vector<pair<int, int>> vc, int n, int k) {
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            if(vc[i].first <= j && vc[i].second + cache[i-1][j-vc[i].first] > cache[i-1][j]) 
                cache[i][j] = vc[i].second + cache[i-1][j-vc[i].first];
        }
    }
}

int main() {
    int n, k, w, v;
    vector<pair<int, int>> vc;
    cin >> n >> k;
    vc.resize(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> w >> v;
        vc[i] = make_pair(w, v);
    }
    solve(vc, n, k);
    cout << cache[n][k];
}