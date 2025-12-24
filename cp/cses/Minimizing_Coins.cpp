#include <bits/stdc++.h>
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
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int &i : c) cin >> i;
    sort(c.begin(), c.end());

    vector<int> memo(x + 1, -1);
    memo[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (auto it : c) {
            if (it > i) {
                break;
            } else if (memo[i - it] != -1) {
                if (memo[i] == -1) {
                    memo[i] = memo[i - it] + 1;
                } else {
                    memo[i] = min(memo[i], memo[i - it] + 1);
                }
            }
        }
        if (memo[i] == 0) memo[i] = -1;
    }

    cout << memo[x] << endl;
}

int32_t main() {
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