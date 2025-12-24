#include <bits/stdc++.h>
#include <numeric>
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    int sum = accumulate(a.begin( ), a.end( ), 0LL);
    int left = k, right = sum;

    auto check = [&](int presses) {
        vector<int> b = a;
        sort(b.begin( ), b.end( ));
        int cans = 0;
        for (int i = 0; i < n; i++) {
            cans += min(b[i], presses / (n - i));
            presses -= min(b[i], presses / (n - i));
        }
        return cans >= k;
    };

    int res = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << res << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve( );
    }

    return 0;
}