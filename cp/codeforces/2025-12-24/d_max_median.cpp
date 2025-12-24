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

const int inf = 1e18;

void solve( ) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &i : a) cin >> i;

        // binary search on the result
        auto check = [&](int med) -> bool {
                vector<int> b(n + 1);
                for (int i = 1; i <= n; i++) b[i] = (a[i - 1] >= med) ? 1 : -1;

                vector<int> pref(n + 1);
                for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + b[i];

                int mnPref = 0;
                for (int i = k; i <= n; i++) {
                        mnPref = min(mnPref, pref[i - k]);
                        if (pref[i] - mnPref > 0) return true;
                }

                return false;
        };

        int low = 1, high = n;
        int res = 1;

        while (low <= high) {
                int mid = low + (high - low) / 2;
                if (check(mid)) {
                        res = mid;
                        low = mid + 1;
                } else {
                        high = mid - 1;
                }
        }

        cout << res << endl;
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
