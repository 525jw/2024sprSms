#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, W, maxprofit = 0;
vector<int> w, p;
vector<bool> include, bestset;

typedef struct _sorting {
    int w;
    int p;
    double e;
} sorting;

bool compare(const sorting a, const sorting b) {
    return a.e > b.e;
}

bool promising(int i, int profit, int weight) {
    int j, k, totweight;
    float bound;
    if (weight >= W)
        return false;
    else {
        j = i + 1;
        bound = profit;
        totweight = weight;
        while (j <= n && totweight + w[j] <= W) {
            totweight += w[j];
            bound += p[j];
            j++;
        }
        k = j;
        if (k <= n)
            bound += (W - totweight) * ((float)p[k] / w[k]);
        return bound > maxprofit;
    }
}

void array_copy(vector<bool> &a, vector<bool> &b) {
    for (int i = 1; i <= n; i++)
        b[i] = a[i];
}

void knapsack4(int i, int profit, int weight) {
    cout << i << " " << weight << " " << profit << " ";

    int j = i + 1;
    float bound = profit;
    int totweight = weight;
    while (j <= n && totweight + w[j] <= W) {
        totweight += w[j];
        bound += p[j];
        j++;
    }
    int k = j;
    if (k <= n)
        bound += (W - totweight) * ((float)p[k] / w[k]);

    cout << bound << " " << maxprofit << endl;

    if (weight <= W && profit > maxprofit) {
        maxprofit = profit;
        array_copy(include, bestset);
    }

    if (promising(i, profit, weight)) {
        include[i + 1] = true;
        knapsack4(i + 1, profit + p[i + 1], weight + w[i + 1]);
        include[i + 1] = false;
        knapsack4(i + 1, profit, weight);
    }
}

int main() {
    cin >> n >> W;
    w.resize(n + 1);
    p.resize(n + 1);
    include.resize(n + 1, false);
    bestset.resize(n + 1, false);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    vector<sorting> sortinging(n + 1);
    for (int i = 1; i <= n; i++)
        sortinging[i] = {w[i], p[i], (double)p[i] / (double)w[i]};
    sort(sortinging.begin() + 1, sortinging.end(), compare);
    for (int i = 1; i <= n; i++) {
        w[i] = sortinging[i].w;
        p[i] = sortinging[i].p;
    }

    knapsack4(0, 0, 0);
    cout << maxprofit << endl;
    for (int i = 1; i <= n; i++) {
        if (bestset[i]) {
            cout << w[i] << " " << p[i];
            bool flag = false;
            for (int j = i + 1; j <= n; j++)
                if (bestset[j]) flag = true;
            if (flag) cout << endl;
        }
    }
    return 0;
}