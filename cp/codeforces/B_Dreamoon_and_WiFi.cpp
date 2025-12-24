#include <bits/stdc++.h>
#include <cmath>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

void solve() {
    string a, b;
    cin >> a >> b;
    int actual_sum = 0;
    int curr_sum = 0;

    for (char c : a) {
        if (c == '+') {
            actual_sum++;
        } else {
            actual_sum--;
        }
    }

    int q = 0;
    for (char c : b) {
        if (c == '+') {
            curr_sum++;
        } else if (c == '-') {
            curr_sum--;
        } else {
            q++;
        }
    }

    int diff = actual_sum - curr_sum;
    double total_ways = 1.0 * (1 << q);
    double valid_ways = 0;

    // how many sums can be formed using q numbers (+1 and -1 only)
    // such that the sum is equal to diff
    for (int i = 0; i < (1 << q); i++) {
        int sum = 0;
        for (int j = 0; j < q; j++) {
            if (i & (1 << j)) {
                sum++;
            } else {
                sum--;
            }
        }
        if (sum == diff) {
            valid_ways++;
        }
    }

    cout << valid_ways / total_ways << endl;
}

int32_t main() {
    //  The answer will be considered correct if its relative or absolute error
    //  doesn't exceed 10 - 9.
    cout << fixed << setprecision(12);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}