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
        int n;
        cin >> n;

        auto printAns = [&](int x) -> void {
                cout << "! " << x << endl;
                cout.flush( );
        };

        auto query = [&](int l, int r) -> int {
                if (l >= r) return -1;
                cout << "? " << l << " " << r << endl;
                cout.flush( );
                int res;
                cin >> res;
                return res;
        };

        int L = 1, R = n;
        int ridx = query(L, R);

        if (ridx == query(L, ridx) && ridx != 1) {
                // max in first half
                L = 1, R = ridx;
                while (R - L > 1) {
                        int mid = (L + R) / 2;
                        if (ridx == query(mid, ridx)) {
                                L = mid;
                        } else {
                                R = mid;
                        }
                }
                printAns(L);
        } else {
                // max in second half
                L = ridx, R = n;
                while (R - L > 1) {
                        int mid = (L + R) / 2;
                        if (ridx == query(ridx, mid)) {
                                R = mid;
                        } else {
                                L = mid;
                        }
                }
                printAns(R);
        }
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
