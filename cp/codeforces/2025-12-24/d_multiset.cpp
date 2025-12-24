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

const int inf = 1e6 + 1;

void solve( ) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int &i : a) cin >> i;
        vector<int> queries(q);
        for (int &i : queries) cin >> i;

        auto countLessEq = [&](int x) -> int {
                int cnt = 0;
                for (int i : a) {
                        if (i <= x) cnt++;
                }
                for (auto it : queries) {
                        if (it > 0) {
                                if (it <= x) cnt++;
                        } else {
                                if (cnt >= abs(it)) cnt--;
                        }
                }
                return cnt;
        };

        if (countLessEq(inf) == 0) {
                cout << 0 << endl;
                return;
        }

        int low = 0;
        int high = inf + 5;
        int res = -1; // final element

        while (low < high) {
                int mid = low + (high - low) / 2;
                if (countLessEq(mid) > 0) {
                        res = mid;
                        high = mid;
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
