#include <bits/stdc++.h>
#include <iostream>
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

void solve( ) {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int &i : x) cin >> i;

    vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));

    auto recur = [&](auto &&self, int i, int j) -> int {
        if (i > j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int pick_left = x[i] + min(self(self, i + 2, j), self(self, i + 1, j - 1));
        int pick_right = x[j] + min(self(self, i + 1, j - 1), self(self, i, j - 2));

        return memo[i][j] = max(pick_left, pick_right);
    };

    cout << recur(recur, 0, n - 1) << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve( );
    }

    return 0;
}