#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

/*
    given n items, weight of ith item is 2^i
    cost of ith item is cost[i]
    min amount needed to purchase the items such that combined weight is atleast min_weight
*/

int min_amount(int n, vector<int> &cost, int min_weight) {
    vector<int> min_cost(n, 0);
    min_cost[0] = cost[0];
    for (int i = 1; i < n; i++) {
        min_cost[i] = min(2 * min_cost[i - 1], cost[i]);
    }

    // if min_weight is power of 2:
    if ((min_weight & (min_weight - 1)) == 0) {
        int idx = log2(min_weight);
        if (idx >= n) {
            return min_cost[n - 1] * (min_weight / (1 << (n - 1)));
        } else {
            return min_cost[idx];
        }
    }

    // if min_weight is not power of 2:
    int ans = 0;
    for (int i = 0; i < n && min_weight > 0; i++) {
        if (min_weight & (1 << i)) {
            ans += min_cost[i];
            min_weight -= (1 << i);
        }
    }

    // handle remaining weight when min_weight >= n
    if (min_weight > 0) {
        ans += min_cost[n - 1] * ((min_weight + (1 << (n - 1)) - 1) / (1 << (n - 1)));
    }

    return ans;
}

int main( ) {
    int n, min_weight;
    cin >> n >> min_weight;
    vector<int> cost(n);
    for (int &i : cost) cin >> i;
    cout << min_amount(n, cost, min_weight) << endl;
    return 0;
}