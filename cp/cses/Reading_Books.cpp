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
    vector<int> books(n);
    for (int &i : books) cin >> i;

    int mx = *max_element(books.begin(), books.end());
    int sum = accumulate(books.begin(), books.end(), 0LL);

    cout << max(2 * mx, sum) << endl;
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
