//Coin Change Problem (Greedy Approach)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void coinChangeGreedy(int coins[], int n, int amount) {
    sort(coins, coins + n, greater<int>());
    vector<int> result;

    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            result.push_back(coins[i]);
        }
    }

    cout << "Coins used: ";
    for (int c : result)
        cout << c << " ";
    cout << endl;
}

int main() {
    int coins[] = {1, 2, 5, 10, 20, 50, 100};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 93;

    coinChangeGreedy(coins, n, amount);
    return 0;
}
