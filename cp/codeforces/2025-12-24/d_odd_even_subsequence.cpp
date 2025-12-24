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

        auto check = [&](int mid) -> bool {
                int l1 = 0, l2 = 0;

                // case1: be careful at odd place
                for (int i = 0; i < n; i++) {
                        if (l1 % 2 == 1)
                                l1++;
                        else {
                                if (a[i] <= mid) l1++;
                        }
                }

                // case2: be careful at even places
                for (int i = 0; i < n; i++) {
                        if (l2 % 2 == 0) {
                                l2++;
                        } else {
                                if (a[i] <= mid) l2++;
                        }
                }

                return (l1 >= k || l2 >= k);
        };

        int low = *min_element(a.begin( ), a.end( ));
        int high = *max_element(a.begin( ), a.end( ));
        int res = 0;

        while (low <= high) {
                int mid = low + (high - low) / 2;
                if (check(mid)) {
                        res = mid;
                        high = mid - 1;
                } else {
                        low = mid + 1;
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
