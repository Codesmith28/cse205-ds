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
    for (int &i : a) cin >> i;

    multiset<int> towers;
    for (int i = 0; i < n; i++) {
        auto it = towers.upper_bound(a[i]);
        if (it != towers.end()) {
            cout << "removed " << *it << endl;
            /*towers.erase(it);*/
        }
        /*cout << "inserted " << a[i] << endl;*/
        towers.insert(a[i]);
        cout << endl;
    }

    cout << towers.size() << endl;
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
