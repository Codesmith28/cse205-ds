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

int minSeg(int n, vector<int> &threads) {
    vector<int> temp = threads;
    int res1 = 0, res2 = 0;

    // case1: start from idx 1 (odd indices)
    for (int i = 1; i < n; i += 2) {
        int mx = max(threads[i - 1], threads[i + 1]) + 1;
        int diff = mx - threads[i];
        if (diff >= 0) {
            res1 += diff;
            threads[i] += diff;
        }
    }

    threads = temp;

    // case2: start from idx 2 (even indices)
    if (n > 3) {
        for (int i = 2; i < n; i += 2) {
            int mx = max(threads[i - 1], (threads[i + 1])) + 1;
            int diff = mx - threads[i];
            if (diff >= 0) {
                res2 += diff;
                threads[i] += diff;
            }
        }
    }

    return min(res1, res2);
}

void solve() {
    int n;
    cin >> n;
    vector<int> threads(n);
    for (int &thread : threads) {
        cin >> thread;
    }
    cout << minSeg(n, threads) << endl;
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
