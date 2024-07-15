//not mine, from study group
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Item* ItemPtr;
typedef struct Item {
    int id;
    int weight;
    int profit;
    int profitPerUnit;
} Item;

int n, W, maxProfit;
float prevBound;
vector<Item> items;
vector<bool> include, bestset;

bool compareItem(Item item1, Item item2);
void knapsack4(int i, int profit, int weight);
bool promising(int i, int profit, int weight);

int main() {
    cin >> n >> W;
    items.resize(n + 1);
    include.resize(n + 1);
    bestset.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> items[i].weight;
    }
    for (int i = 1; i <= n; i++) {
        cin >> items[i].profit;
        items[i].profitPerUnit = items[i].profit / items[i].weight;
    }

    sort(items.begin() + 1, items.end(), compareItem);

    maxProfit = 0;
    knapsack4(0, 0, 0);
    cout << maxProfit << endl;
    for (int i = 1; i <= n; i++) {
        if (bestset[i])
            cout << items[i].weight << " " <<items[i].profit << endl;
    }

    return 0;
}

bool compareItem(Item item1, Item item2) {
    if (item1.profitPerUnit > item2.profitPerUnit)
        return true;
    return false;
}

void knapsack4(int i, int profit, int weight) {
    if (weight <= W && profit > maxProfit) {
        maxProfit = profit;
        copy(include.begin(), include.end(), bestset.begin());
    }

    if (promising(i, profit, weight)) {
        include[i + 1] = true;
        knapsack4(i + 1, profit + items[i + 1].profit, weight + items[i + 1].weight);
        include[i + 1] = false;
        knapsack4(i + 1, profit, weight);
    }
}

bool promising(int i, int profit, int weight) {
    int j, k, totalWeight;
    float bound;

    if (weight >= W) {
        cout << i << " " << weight << " " << profit << " " << prevBound << " " << maxProfit << endl;
        return false;
    }
    else {
        j = i + 1;
        bound = profit;
        totalWeight = weight;
        while (j <= n && totalWeight + items[j].weight <= W) {
            totalWeight += items[j].weight;
            bound += items[j].profit;
            j++;
        }
        k = j;
        if (k <= n)
            bound += (W - totalWeight) * ((float)items[k].profit / items[k].weight);

        cout << i << " " << weight << " " << profit << " " << bound << " " << maxProfit << endl;
        prevBound = bound;
        
        return bound > maxProfit;
    }
}