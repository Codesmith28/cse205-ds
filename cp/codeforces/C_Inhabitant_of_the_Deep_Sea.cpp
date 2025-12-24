#include <bits/stdc++.h>
#include <deque>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n, k;
    cin >> n >> k;

    deque<int> dq(n);
    for (int i = 0; i < n; i++) {
        cin >> dq[i];
    }

    while (dq.size() > 1 and k) {
        int mn = min(dq.front(), dq.back());

        if (k < 2 * mn) {
            dq.front() -= (k / 2 + k % 2);
            dq.back() -= (k / 2);
            k = 0;
        } else {
            dq.front() -= mn;
            dq.back() -= mn;
            k -= 2 * mn;
        }

        if (dq.front() == 0) dq.pop_front();
        if (dq.back() == 0) dq.pop_back();
    }

    int ans = n - dq.size();
    cout << ans + (dq.size() and dq.front() <= k) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}