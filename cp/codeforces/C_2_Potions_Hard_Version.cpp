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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    priority_queue<int, vector<int>, greater<int>> pq;
    int curr = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        curr += a[i];
        pq.push(a[i]);
        ans++;
        while (curr < 0) {
            curr -= pq.top();
            pq.pop();
            ans--;
        }
    }

    cout << ans << endl;
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