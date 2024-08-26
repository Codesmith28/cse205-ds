#include <bits/stdc++.h>
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

int large = 1e9, b;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        cin >> b;
        adj[b - 1].push_back(i);
    }

    auto poss = [&](int node, int mn, auto &&poss) -> bool {
        if (mn > large) return false;
        bool leaf = true;

        if (node) mn += max(0ll, mn - a[node]);
        for (auto child : adj[node]) {
            leaf = false;
            if (!poss(child, mn, poss)) return false;
        }

        return (!leaf or mn <= a[node]);
    };

    int low = 1, high = large;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (poss(0, mid, poss))
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << a[0] + low - 1 << endl;
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